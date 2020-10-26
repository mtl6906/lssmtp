#ifndef LS_SMTP_SMTPCONFIG_H
#define LS_SMTP_SMTPCONFIG_H

#include "ls/Config.h"

namespace ls
{
	namespace smtp
	{
		class SmtpConfig : Config
		{
			public:
				std::string url;
				std::string username;
				std::string password;
				int buffersize;
				SmtpConfig();
		};
	}
}

#endif
