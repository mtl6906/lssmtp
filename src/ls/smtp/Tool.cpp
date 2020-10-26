#include "ls/smtp/Tool.h"

using namespace std;

namespace ls
{
	namespace smtp
	{
		Tool *Tool::instance = new Tool();
		Tool::Tool() : client(new Client(config.url, config.username, config.password, config.buffersize))
		{

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
