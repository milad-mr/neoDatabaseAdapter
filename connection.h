#include <curl/curl.h>
#include <vector>
#include <string>
class Connection{
	
	CURL *curl;
	std::string response;
	curl_slist *headers;
public:
	enum RequestType{
		POST,
		GET	
	};
	Connection();
	CURLcode request(std::string url, RequestType reqType, std::string data);
	//size_t write_callback(const char *ptr, size_t size, size_t nmemb, std::string *stream);

	
	
};
	