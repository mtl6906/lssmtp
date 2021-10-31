#include "ls/smtp/Request.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "unistd.h"
#include "netdb.h"
#include "ls/net/Client.h"
#include "ls/DefaultLogger.h"
#include "ls/io/InputStream.h"
#include "ls/io/OutputStream.h"
#include "ls/Exception.h"

using namespace std;

namespace ls
{
	namespace smtp
	{
		net::Socket* connect(const User &user)
		{
			hostent *he = gethostbyname(user.url.c_str());
			LOGGER(ls::INFO) << inet_ntoa(*(struct in_addr *)he -> h_addr_list[0]) << ls::endl;
			net::Client client(inet_ntoa(*(struct in_addr*)he -> h_addr_list[0]), 25);
			return new net::Socket (client.connect());
		}

		Request::Request(const User &user, int buffersize) : user(user), sbuffer(buffersize), sock(connect(user))
		{
	
		}

		void Request::sendAndRecv(io::InputStream &in, io::OutputStream &out)
		{
			out.write();
			try
			{
				in.read();
			}
			catch(Exception &e)
			{
				rbuffer.clear();
				sbuffer.clear();
				return;
			}
			LOGGER(ls::INFO) << in.split() << endl;
			rbuffer.clear();
			sbuffer.clear();
		}

		void Request::send(const Message &message)
		{
			io::InputStream in(sock -> getReader(), &rbuffer);
			io::OutputStream out(sock -> getWriter(), &sbuffer);
			out.append("helo ");
			out.append(user.url);
			out.append("\r\n");
			sendAndRecv(in, out);

			out.append("auth login\r\n");
			sendAndRecv(in, out);
	
			string username;
			string password;
			base64.encode(user.username, username);
			base64.encode(user.password, password);
			out.append(username);
			out.append("\r\n");
			sendAndRecv(in, out);
	
			out.append(password);
			out.append("\r\n");
			sendAndRecv(in, out);

			out.append("MAIL FROM:<");
			out.append(user.username);
			out.append(">\r\n");
			sendAndRecv(in, out);

			out.append("RCPT TO:<");
			out.append(message.recver);
			out.append(">\r\n");
			sendAndRecv(in, out);

			out.append("DATA\r\n");
			sendAndRecv(in, out);

			out.append("FROM: ");
			out.append(user.username);
			out.append("\r\nTO:");
			out.append(message.recver);
			out.append("\r\nSUBJECT: ");
			out.append(message.title);
			out.append("\r\n\r\n");
			out.append(message.content);
			out.append("\r\n.\r\n");
			sendAndRecv(in, out);

			out.append("QUIT\r\n");
			sendAndRecv(in, out);
		}

	}
}
