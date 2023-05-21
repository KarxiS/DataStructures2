#pragma once
#include <string>
using namespace std;

class Kraj {
public:
    int sortnumber;
    string kod;
    string officialTitle;
    string mediumTitle;
    string shortTitle;
    int note;

    Kraj(int sortnum, string k, string officialTitle, string mediumTitle, string shortTitle, int n);
    string getOffTitle();
    string toString();


};