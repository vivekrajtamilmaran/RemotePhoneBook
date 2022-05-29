#include <iostream>
using namespace std;
class Phonebook{
        string name , phonenumber ;

        public :
                Phonebook();
                Phonebook(string name , string phonenumber );
                bool storeData(string filename);
                string removeData(vector<string> afterRemoved,string filename);
};

