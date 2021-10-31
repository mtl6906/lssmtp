#ifndef LS_SMTP_TOOL_H
#define LS_SMTP_TOOL_H

#include "ls/smtp/Request.h"
#include "ls/smtp/Config.h"

namespace ls
{
	namespace smtp
	{
		class Tool
		{
			public:
				Tool();
				~Tool();
				Request *getRequest();
			protected:
				Config config;
				Request *request;
		};
	}
}
#endif
