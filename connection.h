#include <curl/curl.h>
#include <vector>
#include <string>
class Connection{
	
	CURL *curl;
	CURLcode response;
	curl_slist *headers;
public:
	enum RequestType{
		POST,
		GET	
	};
	Connection();
	CURLcode request(std::string url, RequestType reqType, std::string data);

	
	
};
	