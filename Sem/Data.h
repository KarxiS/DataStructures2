#pragma once
#include <string>
using namespace std;

class Data {

public:
    string sortnumber;
    string kod;
    string officialTitle;
    string mediumTitle;
    string shortTitle;
    string note;
    string type;
   
    
    Data(string sortnum, string k, string offTitle, string medTitle, string shTitle, string n);
    Data() : sortnumber(), kod(), officialTitle(), mediumTitle(), shortTitle(), note() {}
    string getOffTitle();
    string getMedTitle();
    bool hasType(const string& str) const;
    bool startsWith(const string& str) const;
    bool containsStr(const string& str) const;
    string getKod();
    int getKodInt();
    string getNote();
    string toString();
    void setNezamestnanost(string nezam);
    string getNezamestnanost();
    ~Data();
    
    bool operator==(const Data& other) const {
        return other.officialTitle == this->officialTitle;
    }
    

};




