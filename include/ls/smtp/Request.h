#ifndef LS_SMTP_REQUEST_H
#define LS_SMTP_REQUEST_H

#include "ls/Buffer.h"
#include "ls/Base64.h"
#include "ls/io/InputStream.h"
#include "ls/io/OutputStream.h"
#include "ls/CopyableItem.h"
#include "ls/net/Socket.h"

namespace ls
{
	namespace smtp
	{
		class Message
		{
			public:
				std::string title;
				std::string content;
				std::string recver;
		};
		
		class User
		{
			public:
				std::string url;
				std::string username;
				std::string password;
		};

		class Request
		{
			public:
				Request(const User &user, int buffersize);
				void send(const Message &message);
			private:
				void sendAndRecv(io::InputStream &in, io::OutputStream &out);
				User user;
				Message message;
				Buffer sbuffer;
				Buffer rbuffer;
				Base64 base64;
				net::Socket *sock;
		};

/*
		class Request : public CopyableItem
		{
			public:
				void copyTo(char *text, int len) override;
				int lengthOfString() override;
			protected:
				void parse(const std::string &text) override;
				string method;
		};
*/

	}
}

#endif
