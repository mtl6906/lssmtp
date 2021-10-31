#include "ls/smtp/Config.h"
#include "ls/DefaultLogger.h"

using namespace std;

namespace ls
{
	namespace smtp
	{
		Config::Config()
		{
			load();
		}

		Config::~Config()
		{
		
		}

		void Config::init()
		{
			json::api.get(root, "url", url);
			json::api.get(root, "username", username);
			json::api.get(root, "password", password);
			json::api.get(root, "buffersize", buffersize);

			LOGGER(ls::INFO) << "url: " << url << ls::endl;
			LOGGER(ls::INFO) << "username: " << username << ls::endl;
			LOGGER(ls::INFO) << "password: " << password << ls::endl;
			LOGGER(ls::INFO) << "buffersize: " << buffersize << ls::endl;
		}

		string Config::getConfigPath()
		{
			char *configPath = getenv("SMTP_CONFIG_PATH");
			if(configPath == nullptr)
				configPath = (char *)"smtp.json";
			return configPath;
		}
	}
}
