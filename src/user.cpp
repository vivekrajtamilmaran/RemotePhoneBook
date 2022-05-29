#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <string>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <vector>
#include <algorithm>
#include <sys/ipc.h>
#include <fstream>
#include <sstream>
#include "../include/user.h"
using namespace std;
        
User::User(){};
User::User::User(string username ,string password){
	this->username = username;
        this->password = password;
}
User::User(string username ,string password ,vector<string>group){
	this->username = username;
      this->password = password;
      for(auto i: group){
      	this->group.push_back(i);
      }
}



bool  User::authenticate(User user){
	if(this->username == user.username && this->password == user.password ){
      	return true ;
      }
      else{
      	return false ;
      }
}
string User::addData(string input1 ,string input2,string filename){
	Phonebook phonebook(input1,input2);
      if(phonebook.storeData(filename)){
      	return "yes";
      }
      else{
      	return "no";
      }

}
string User::removeContact(string input,string filename){
      Phonebook phonebook ;
      vector <string> afterRemoved ;
      string line = "" ;
      ifstream infile;
      infile.open("/home/cguser11/phonebook/db/"+filename + ".txt");
      if(infile.is_open()){
      	while(getline(infile,line)){
            	string name ,phonenumber ;
                  stringstream ss(line);
                  getline(ss,name,',');
                  getline(ss,phonenumber,',');
                  if(name!="" && name!=input){
            	      afterRemoved.push_back(name + ":" + phonenumber );
                  }
              }
         }
         infile.close();
         string yes =phonebook.removeData(afterRemoved,filename);
         return yes ;
}
vector<string> User::listData(string input,string filename){
	ifstream infile ;
      vector<string> listedContact;
      string line = "";
      if(filename!=""){

            infile.open("/home/cguser11/phonebook/db/"+filename + ".txt");
            listedContact.push_back("The contacts in the " + filename + " group\n");
            if(infile.is_open()){
            	while(getline(infile,line)){
                  	string name ,phonenumber ;
                        stringstream ss(line);
                        getline(ss,name,',');
                        getline(ss,phonenumber,',');
                        if(name != "" && phonenumber !=""){
                        	if(name.substr(0,input.size()) == input){
                              	listedContact.push_back("Name :" + name + "\tPhonenumber :" + phonenumber + "\n");
                              }
                        }
            	}
     		}
    		infile.close();
     	}
      else{
      	infile.open("/home/cguser11/phonebook/db/public group.txt");
            if(infile.is_open()){
            	listedContact.push_back("The contacts in the public group\n");
                  while(getline(infile,line)){
                  	string name ,phonenumber ;
                        stringstream ss(line);
                        getline(ss,name,',');
                        getline(ss,phonenumber,',');
                        if(name != "" && phonenumber != ""){
                        	if(name.substr(0,input.size()) == input){
                              	listedContact.push_back("Name :" + name + "\tPhonenumber :" + phonenumber + "\n");
                              }
                        }
                  }
             }
     infile.close();
     }
     return listedContact;
}


bool User::findUser(string username){
	return this->username == username ;
}





string User::chgrp(string input){
	for(auto grpName : group){
      	if(grpName == input){
            	return input ;
            }
       }
       return "no";

}


