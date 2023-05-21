#include <libds/heap_monitor.h>
#include "Nacitavac.h"
#include <vector>
#include <sstream>
#include "Data.h"
#include <iostream>
#include <libds/amt/implicit_sequence.h>


using namespace std;


Nacitavac::Nacitavac(string menoSuboru)
{
    handler.open(menoSuboru, ios::in);
    if (!handler.is_open()){
        cout <<"zly input"<<endl;
        exit;

        }
    std::cout << "nacitavam novy subor:" << menoSuboru << endl;
}

void Nacitavac::setMenoSuboru(string menoSuboru)
{
    handler.open(menoSuboru, ios::in);
}





ds::amt::ImplicitSequence<Data> Nacitavac::dajData()
{
    string slovo;
    
    ds::amt::ImplicitSequence<Data> sekvencia;

        string riadok;
        getline(handler, riadok);
        while (getline(handler, riadok)) {
            stringstream s(riadok);
            vector<string> values;

            while (getline(s, slovo, ';')) {
                values.push_back(slovo);
            }
            if (values.size() == 6) {
                string sortnumber = values[0];
                string kod = values[1];
                string officialTitle = values[2];
                string mediumTitle = values[3];
                string shortTitle = values[4];
                string note = values[5];
                sekvencia.insertLast().data_= Data(sortnumber, kod, officialTitle, mediumTitle, shortTitle, note);
               
                
                s.clear();
            }

        }
    

        return sekvencia;
}


ds::amt::ImplicitSequence<Data*> Nacitavac::dajDataSmernik()
{
    string slovo;

    ds::amt::ImplicitSequence<Data*> sekvencia;

    string riadok;
    getline(handler, riadok);
    while (getline(handler, riadok)) {
        stringstream s(riadok);
        vector<string> values;

        while (getline(s, slovo, ';')) {
            values.push_back(slovo);
        }
        if (values.size() == 6) {
            string sortnumber = values[0];
            string kod = values[1];
            string officialTitle = values[2];
            string mediumTitle = values[3];
            string shortTitle = values[4];
            string note = values[5];
            sekvencia.insertLast().data_ = new Data(sortnumber, kod, officialTitle, mediumTitle, shortTitle, note);


            s.clear();
        }

    }


    return sekvencia;
}




Nacitavac::~Nacitavac()
{
    handler.close();
}