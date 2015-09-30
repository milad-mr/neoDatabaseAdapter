#include "connection.h"
#include <string>

class Cursor{
	std::vector <std::string> commands;
	Connection *connector;
public:
	Cursor();
	void AddCommand(std::string command);
	CURL_EXTERN CURLcode Execute();
	
	
};
