#include <iostream>
#include <signal.h>
#include "../include/client.h"
int sockid ;
using namespace std ;

using namespace std;
void signalHandler(int signal){
        if(signal==SIGINT){
                send(sockid,"bye",3,0);
                exit(0);
        }
}

int main () {
        signal(SIGINT,signalHandler);
        string recvdata,credentials , commands;
        Client client;
        sockid=client.getSockfd();
        credentials=client.getCredentials() ;
        client.serverConnect() ;
        client.sendData(credentials);
        recvdata=client.recvData();
        string type =recvdata ;
        client.displayRecvData(recvdata) ;
        while(1){
                commands = "";
                commands=client.getUserCommands(type) ;
                if( commands != ""){
               	 client.sendData(commands);
               
                   recvdata = client.recvData();
                   client.displayRecvData(recvdata);

                }
                else{
                        cout << "Subcommand can't be Null" << endl;
                        continue;
                }

        }
        return 0;
}

