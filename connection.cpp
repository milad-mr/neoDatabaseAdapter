#include "connection.h"
#include <iostream>
Connection::Connection(){
	curl = curl_easy_init();
	headers = curl_slist_append(headers, "Authorization: bmVvNGo6MTIz");
	headers = curl_slist_append(headers, "Content-type: application/json");		
	curl_easy_setopt(curl, CURLOPT_HEADER, 1);
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
	
	
}
CURLcode Connection::request(std::string url, RequestType reqType, std::string data){
	if(reqType == POST){
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
	}
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	CURLcode a =  curl_easy_perform(curl);
	std::cout << a;
	return a;
	
}


