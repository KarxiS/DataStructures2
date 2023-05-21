
#include "Kraj.h"

Kraj::Kraj(int sortnum, string k, string officialTitle, string mediumTitle, string shortTitle, int n) {
    sortnumber = sortnum;
    kod = k;
    officialTitle = officialTitle;
    mediumTitle = mediumTitle;
    shortTitle = shortTitle;
    note = n;
}

string Kraj::getOffTitle()
{
	return this->officialTitle;
}

string Kraj::toString()
{
    return to_string(sortnumber) + " "+ kod + officialTitle + " "
        + mediumTitle + " "+ shortTitle + " " + to_string(note) + "\n";
}


