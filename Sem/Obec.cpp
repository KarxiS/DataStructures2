
#include "Obec.h"
#include "Data.h"




Obec::Obec(string sortnum, string k, string offTitle, string medTitle, string shTitle, string n)
{
    
        sortnumber = sortnum;
        kod = k;
        officialTitle = offTitle;
        mediumTitle = medTitle;
        shortTitle = shTitle;
        note = n;
    
}


string Obec::getOffTitle()
{
	return this->officialTitle;
}

string Obec::toString()
{
	return sortnumber + " " + kod + officialTitle + " "
		+ mediumTitle + " " + shortTitle + " " + note + "\n";
}
