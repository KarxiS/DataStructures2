#include "Data.h"



Data::Data(string sortnum, string k, string offTitle, string medTitle, string shTitle, string n)
{

    sortnumber = sortnum;
    kod = k;
    officialTitle = offTitle;
    mediumTitle = medTitle;
    shortTitle = shTitle;
    note = n;

    //default
    this->type = "kraj";
    if (this->note.length() == 6) {
       this->type="obec";
    }
    if (this->note.length() == 3) {
        this->type = "okres";
    }
    if (this->sortnumber == "SK") {
        this->type = "SK";
    }
}

string Data::getOffTitle()
{
    return this->officialTitle;
}

string Data::getMedTitle()
{
    return this->mediumTitle;
}

bool Data::hasType(const string& str) const
{
    if (this->note.length() == 6) {
        return ("obec"==str);
    }
    if (this->note.length() == 3) {
        return ("okres" == str);
    }
    if (this->type == "SK") {
        return (false);
    }
    //default
    return ("kraj" == str);
}

bool Data::startsWith(const string& str) const
{
    string string1 = this->officialTitle;
        if (this->officialTitle.length() < str.length()) {
        return false;
    }
    string zaciatokStr = this->officialTitle.substr(0, str.length());
    return  (zaciatokStr == str);

}

bool Data::containsStr(const string& str) const
{
    if (this->officialTitle.length() < str.length()) {
        return false;
    }
    string string1 = this->officialTitle;

    int zaciatok = this->officialTitle.find(str);
    return (zaciatok > -1);
}



string Data::getKod() 
{
    return this->kod;
}

int Data::getKodInt()
{
    
    return stol(this->kod);
}

string Data::getNote()
{
    return this->note;
}


string Data::toString()
{
    return   officialTitle + " " + kod +  " "
        + mediumTitle + " " + shortTitle + " " + (note)+"\n";
}



Data::~Data()
{
    

}
