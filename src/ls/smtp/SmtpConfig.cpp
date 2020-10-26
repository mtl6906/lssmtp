#include "ls/smtp/SmtpConfig.h"
#include "ls/util.h"

#define SMTPCONFIG_LOG "SMTPCONFIG_LOG"

namespace ls
{
	using namespace json;
	namespace smtp
	{
		SmtpConfig::SmtpConfig()
		{
			char *configPath = getenv("SMTP_CONFIG_PATH");
			if(configPath == nullptr)
				configPath = (char *)"smtp.json";
			Load(configPath);
			GET_STRING(root, "url", url);
			GET_STRING(root, "username", username);
			GET_STRING(root, "password", password);
			GET_INT(root, "buffersize", buffersize);

			ls_log_tag(SMTPCONFIG_LOG, "url: %s", url.c_str());
			ls_log_tag(SMTPCONFIG_LOG, "username: %s", username.c_str());
			ls_log_tag(SMTPCONFIG_LOG, "password: %s", password.c_str());
			ls_log_tag(SMTPCONFIG_LOG, "buffersize: %d", buffersize);
		}
	}
}
