#ifndef LS_SMTP_CONFIG_H
#define LS_SMTP_CONFIG_H

#include "ls/Config.h"

namespace ls
{
	namespace smtp
	{
		class Config : public ls::Config
		{
			public:
				Config();
				~Config() override;
				std::string getConfigPath() override;
				void init() override;
				int buffersize;
				std::string url;
				std::string username;
				std::string password;
				
		};
	}
}

#endif
