#ifndef LS_SMTP_MESSAGE_H
#define LS_SMTP_MESSAGE_H

namespace ls
{
	namespace smtp
	{
		class Message
		{
			public:
				std::string title;
				std::string content;
				std::string recver;	
		};
	}
}

#endif
