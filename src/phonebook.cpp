#include <iostream>
#include <unistd.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "../include/phonebook.h"
using namespace std;

Phonebook::Phonebook(){};
Phonebook::Phonebook(string name , string phonenumber ){
	this->name = name;
      this->phonenumber = phonenumber ;
};
bool Phonebook::storeData(string filename){
	ofstream outfile ;
      if(filename != ""){
            outfile.open("/home/cguser11/phonebook/db/"+filename + ".txt", ios_base::app);
            string contact = name + "," + phonenumber ;
            outfile  << contact << "\n";
            outfile.close();
            return true;
       }
       else{
       	return false;
       }

}
string Phonebook::removeData(vector<string> afterRemoved,string filename){
	ofstream outfile ;
      if(filename != ""){
      	outfile.open("/home/cguser11/phonebook/db/"+filename + ".txt");
      	if(outfile.is_open()){
      		for(auto i : afterRemoved){
      	      	outfile  << i <<  "\n";
      	      }
      	      return "yes" ;
      	}
      	outfile.close();
     	}
      	return "" ;
}


