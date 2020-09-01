#include "ls/json/Json.h"
#include "ls/util.h"
#include "ls/smtp/Tool.h"

using std::string;
using ls::json::String;
using ls::json::Int;

namespace ls
{
	namespace smtp
	{
		Tool *Tool::instance = new Tool();
		Tool::Tool()
		{
			char *configPath = getenv("SMTP_CONFIG_PATH");
			if(configPath == NULL)
				configPath = (char *)"SMTPConfig.json";
			string content;
			if(ReadFullFile(configPath, content) < 0)
				exit(1);
			json::Object root;
			root.ParseFrom(content);
			string url, username, password;
			int buffersize;
			GET_STRING(root, "url", url);
			GET_STRING(root, "username", username);
			GET_STRING(root, "password", password);
			GET_INT(root, "buffersize", buffersize);
			client = new Client(url, username, password, buffersize);
		}
		Tool::~Tool()
		{
			  delete client;
		}
		Tool *Tool::GetInstance()
		{
			return instance;
		}
		Client *Tool::GetClient()
		{
			return client;
		}
	}
}
