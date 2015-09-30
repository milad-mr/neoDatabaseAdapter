#include "neo.h"
#include "iostream"
Cursor::Cursor(){

	connector = new Connection;
	
}



void Cursor::AddCommand(std::string command){
	commands.push_back(command);
}

CURL_EXTERN CURLcode Cursor::Execute(){
	

	std::string data = "{ \"statements\" : [ ";
	for (int i = 0; i < commands.size(); ++ i){
		data += "{\"statement\" : \"" + commands[i] + "\"},";
		
	}
	data = data.substr(0, data.size() - 1);
	data += "]}";
	//std::cout << data;
	CURLcode response = connector->request("http://localhost:7474/db/data/transaction/commit", connector->POST, data);
	//std::cout << response;
	return response;
	
}
#include <iostream>
int main(){
	Cursor cur;
	cur.AddCommand("match(n) return(n)");
	cur.AddCommand("creat(a:adam)");
	std::cout << cur.Execute();
	
		
}