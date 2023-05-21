#pragma once
#include <string>
using namespace std;

class Obec {
public:
    string sortnumber;
    string kod;
    string officialTitle;
    string mediumTitle;
    string shortTitle;
    string note;

    Obec(string sortnum, string k, string offTitle, string medTitle, string shTitle, string n);
    string getOffTitle();
    string toString();

};