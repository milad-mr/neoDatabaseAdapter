#include <iostream>
#include "neo.h"
int main(){
	Cursor cur;
	//cur.AddCommand("match(n) return(n)");
	cur.AddCommand("create(a:mard)");
	cur.AddCommand("create(a:adam)");
	cur.Execute();
	
		
}