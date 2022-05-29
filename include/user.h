#include <iostream>
#include <vector>
#include<algorithm>
#include "../include/phonebook.h"
using namespace std;

class User{
        string username ,password ;
        vector<string> group;
        vector<Phonebook> phonebooks ;
        public:
                User();
                User(string username ,string password);
                User(string username ,string password ,vector<string>group);

                bool  authenticate(User user);
                string addData(string input1 ,string input2,string filename);
                string removeContact(string input,string filename);
                vector<string> listData(string input,string filename);
                bool findUser(string username);
                string chgrp(string input);


};

