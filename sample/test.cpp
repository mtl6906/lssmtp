#include "ls/smtp/Tool.h"

using namespace std;
using namespace ls;

int main()
{
	smtp::Tool tool;
	auto request = tool.getRequest();
	smtp::Message	message;
	message.title = "abcdefg";
	message.content = "sba";
	message.recver = "";
	request -> send(message);
	return 0;
}
