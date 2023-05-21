#pragma once
#include <string>
using namespace std;

 class Okres {     
    public:    
        int sortnumber;       
        string kod;  
        string officialTitle;
        string mediumTitle;
        string shortTitle;
        int note;

        Okres(int sortnum, string k, string offTitle, string medTitle, string shTitle, int n);
           
        string getOffTitle();
        string toString();
        
    };


