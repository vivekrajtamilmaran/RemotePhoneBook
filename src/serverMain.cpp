#include <iostream>
#include "../include/server.h"
using namespace std;
int main(){
	Server server;
   	server.loadDAta();
	server.createSocket();
	server.bindSocket();
	server.listenTo();  
	server.acceptConnections() ;
}
