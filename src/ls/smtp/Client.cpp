#include "ls/smtp/Client.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "netinet/in.h"
#include "unistd.h"
#include "cstring"
#include "netdb.h"
#include "iostream"

using std::cout;
using std::endl;

using std::string;

namespace ls
{
	namespace smtp
	{
		Client::Client(
				const string &url,
				const string &username,
				const string &password, 
				int buffersize) : url(url), username(username), password(password), sbuffer(buffersize)
		{
	
		}

		string &Client::Content()
		{
			return content;
		}

		string &Client::Title()
		{
			return title;
		}	

		string &Client::Recver()
		{
			return recver;
		}

		void Client::SendAndRecv(int fd)
		{	
			send(fd, sbuffer.Begin(), sbuffer.Size(), 0);
			sbuffer.Clear();
			int n = recv(fd, rbuffer.End(), rbuffer.RestSize(), 0);
			rbuffer.MoveBuffersize(n);
			string s(n, '\0');
			rbuffer.Pop(s);
			cout << s << endl;
		}

		int Client::Send()
		{
			hostent *he = gethostbyname(url.c_str());
		
			int fd = socket(AF_INET, SOCK_STREAM, 0);	
			sockaddr_in addr;
			memset(&addr, 0, sizeof(addr));
			addr.sin_family = AF_INET;
			addr.sin_port = htons(25);
			addr.sin_addr = *(in_addr *)he -> h_addr;

			connect(fd, (sockaddr *)&addr, sizeof(addr));

			int n = recv(fd, rbuffer.End(), rbuffer.RestSize(), 0);
			rbuffer.MoveBuffersize(n);
			string s(n, '\0');
			rbuffer.Pop(s);
			cout << s << endl;

			sbuffer.Push("helo ");
			sbuffer.Push(url);
			sbuffer.Push("\r\n");
			SendAndRecv(fd);
	
			sbuffer.Push("auth login\r\n");
			SendAndRecv(fd);
	
			string username64, password64;
			base64.Encode(username, username64);
			base64.Encode(password, password64);
			sbuffer.Push(username64);
			sbuffer.Push("\r\n");
			SendAndRecv(fd);
	
			sbuffer.Push(password64);
			sbuffer.Push("\r\n");
			SendAndRecv(fd);

			sbuffer.Push("MAIL FROM:<");
			sbuffer.Push(username);
			sbuffer.Push(">\r\n");
			SendAndRecv(fd);

			sbuffer.Push("RCPT TO:<");
			sbuffer.Push(recver);
			sbuffer.Push(">\r\n");
			SendAndRecv(fd);

			sbuffer.Push("DATA\r\n");
			SendAndRecv(fd);

			sbuffer.Push("FROM: ");
			sbuffer.Push(username);
			sbuffer.Push("\r\nTO:");
			sbuffer.Push(recver);
			sbuffer.Push("\r\nSUBJECT: ");
			sbuffer.Push(title);
			sbuffer.Push("\r\n\r\n");
			sbuffer.Push(content);
			sbuffer.Push("\r\n.\r\n");
			SendAndRecv(fd);

			sbuffer.Push("QUIT\r\n");
			SendAndRecv(fd);

			return 0;
		}
	}
}
