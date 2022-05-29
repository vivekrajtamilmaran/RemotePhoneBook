#include <iostream>
#include <vector>
#include <algorithm>
#include <sys/socket.h>
#include <sys/ipc.h>
#include <arpa/inet.h>
#include "../include/user.h"
using namespace std;

class Server{
        int sockfd ;
        sockaddr_in servaddr ;
        sockaddr_in cliaddr ;
        vector <User> users ;
        int slen = 0 ,connectfd = 0, mlen = 0 ;
        pid_t pid ;
        public:
        	Server();
                
		int loadDAta();
		int createSocket();
		int bindSocket();
		
		int listenTo(); 
		void acceptConnections();
            	string recvData();
            	string authenticateUser();

};




