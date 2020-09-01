#include "ls/smtp/Tool.h"

using std::string;

int main()
{
	auto client = ls::smtp::Tool::GetInstance() -> GetClient();
	client -> Title() = "abcdefg";
	client -> Content() = "sba";
	client -> Recver() = "zzz5486129@163.com";
	client -> Send();
	return 0;
}
