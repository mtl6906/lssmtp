#ifndef LS_SMTP_TOOL_H
#define LS_SMTP_TOOL_H

#include "ls/smtp/Client.h"
#include "ls/smtp/SmtpConfig.h"

namespace ls
{
	namespace smtp
	{
		class Tool
		{
			static Tool *instance;	
			SmtpConfig config;
			Client *client;
			public:
				Tool();
				~Tool();
				static Tool *GetInstance();
				Client *GetClient();
		};
	}
}
#endif
