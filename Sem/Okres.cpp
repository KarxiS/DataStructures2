#include <string>
#include <string>
#include "Okres.h"
using namespace std;

Okres::Okres(int sortnum, string k, string offTitle, string medTitle, string shTitle, int n)
{
    
    sortnumber = sortnum;
    kod = k;
    officialTitle = offTitle;
    mediumTitle = medTitle;
    shortTitle = shTitle;
    note = n;
    
}

string Okres::getOffTitle()
{
	return this->officialTitle;
}

string Okres::toString()
{
	return to_string(sortnumber) + " " + kod + officialTitle + " "
		+ mediumTitle + " " + shortTitle + " " + to_string(note) + "\n";
}
