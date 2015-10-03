#include "connection.h"
#include <iostream>
 
size_t write_callback(const char *ptr, size_t size, size_t count, std::string *stream)
{//this function no need to be a member of the class.

	stream->append(ptr, size * count);
	return size * count;
	
}
Connection::Connection(){
	curl = curl_easy_init();
	headers = curl_slist_append(headers, "Authorization: bmVvNGo6MTIz");
	headers = curl_slist_append(headers, "Content-type: application/json");		
	curl_easy_setopt(curl, CURLOPT_HEADER, 1);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
}


CURLcode Connection::request(std::string url, RequestType reqType, std::string data){
	if(reqType == POST){
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
	}
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	CURLcode a =  curl_easy_perform(curl);
	std::cout << response;
	return a;
	
}


