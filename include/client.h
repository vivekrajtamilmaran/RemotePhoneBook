#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ipc.h>
using namespace std;
class Client{
        int sockfd;
        sockaddr_in servaddr;
        int portnumber,slen,mlen,connectfd;
        string ip_address;

        public:
                Client();

                int getSockfd();

                string getCredentials();
                int serverConnect( );

                int sendData(string input);

                string recvData();
                string getUserCommands(string type);
                int displayRecvData(string recvData);

                int closeClientConnections();
};

