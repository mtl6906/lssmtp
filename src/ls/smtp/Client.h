#ifndef LS_SMTP_CLIENT_H
#define LS_SMTP_CLIENT_H

#include "ls/Buffer.h"
#include "ls/Base64.h"

namespace ls
{
	namespace smtp
	{
		class Client
		{
			std::string title;
			std::string content;
			std::string recver;
			std::string url;
			std::string username;
			std::string password;
			Buffer sbuffer;
			Buffer rbuffer;
			Base64 base64;
			void SendAndRecv(int fd);
			public:
				Client(
					const std::string &url, 
					const std::string &username,
					const std::string &password,
					int buffersize
				);
				std::string &Title();
				std::string &Content();
				std::string &Recver();
				std::string &Sender();
				int Send();
		};
	}
}

#endif
