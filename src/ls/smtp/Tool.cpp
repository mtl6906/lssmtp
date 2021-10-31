#include "ls/smtp/Tool.h"

using namespace std;

namespace ls
{
	namespace smtp
	{
		Tool::Tool()
		{
			User user;
			user.url = config.url;
			user.username = config.username;
			user.password = config.password;
			request = new Request(user, config.buffersize);
		}
		Tool::~Tool()
		{
			  delete request;
		}
		Request *Tool::getRequest()
		{
			return request;
		}
	}
}
