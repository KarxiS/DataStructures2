
#include "uroven1.h"
#include "Nacitavac.h"
#include "Algoritmus.h"
#include <libds/adt/table.h>

#include "MemoryLeak.h"

auto uroven1::main() -> int
{
    {

       

        /// ////obce



        Algoritmus alg;
        cout << "zadajte nazov suboru (obce.csv,kraje.csv,okresy.csv)" << endl;
        string string1;
        cin >> string1;
        Nacitavac nacitavac(string1);
        strukturaData vektor = nacitavac.dajData();
        cout << "zadajte vyhladavany vyraz" << endl;
        string string2;
        cin >> string2;

        cout << "containsStr alebo startsStr?" << endl;
        string string3;
        cin >> string3;
        strukturaData vektorNaplneny = strukturaData();
        function<bool(const Data&)> startsWith = [&](const Data& d) { return d.startsWith(string2); };
        function<bool(const Data&)> containsStr = [&](const Data& d) { return d.containsStr(string2); };
        function<void(const Data&)> plnicPred = [&](const Data& d) { vektorNaplneny.insertLast().data_ = d; };
        if (string3 == "containsStr") {
            Algoritmus::filterPlnic(vektor.begin(), vektor.end(), containsStr, plnicPred);
            vypisStrukturu(vektorNaplneny);
        }
        else {

            Algoritmus::filterPlnic(vektor.begin(), vektor.end(), startsWith, plnicPred);
            vypisStrukturu(vektorNaplneny);


        }





    }
    _CrtDumpMemoryLeaks();

    return 0;


}

void uroven1::vypisStrukturu(strukturaData& struktura)
{
    int pocitadlo = 0;
    for (Data data : struktura) {
        cout << "INDEX:" << pocitadlo << "  " << data.toString();
        pocitadlo++;
    }
}

void uroven1::vynulujStrukturu(strukturaData& struktura)
{
    struktura.clear();

}

