#ifndef LS_SMTP_TOOL_H
#define LS_SMTP_TOOL_H

#include "ls/smtp/Client.h"

namespace ls
{
	namespace smtp
	{
		class Tool
		{
			static Tool *instance;	
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
