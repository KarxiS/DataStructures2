#include "uroven4.h"
#include "Nacitavac.h"
#include "Algoritmus.h"
#include <libds/amt/hierarchy.h>
#include <libds/amt/explicit_hierarchy.h>
#include "plnicHierarchie.h"
#include "TriediaciAlgoritmus.cpp"
#include <locale>

auto uroven4::main() -> int
{
    string string1 = "kraje.csv";
    Nacitavac nacitavacKraje("kraje.csv");
    ds::amt::ImplicitSequence<Data> vektorKraje = nacitavacKraje.dajData();

    Nacitavac nacitavacOkresy("okresy.csv");
    ds::amt::ImplicitSequence<Data> vektorOkresy = nacitavacOkresy.dajData();

    Nacitavac nacitavacObce("obce.csv");
    ds::amt::ImplicitSequence<Data> vektorObce = nacitavacObce.dajData();
    ds::amt::ImplicitSequence<Data> vektorNaplneny = ds::amt::ImplicitSequence<Data>();


    ds::amt::MultiWayExplicitHierarchy<Data> hierar;
    Data Slovensko("SK", "SK", "SK", " ", " ", " ");
    hierar.emplaceRoot().data_ = Slovensko;
    plnicHierarchie plnic(hierar);
    plnic.naplnKraje(vektorKraje);
    plnic.naplnOkresy(vektorOkresy);
    plnic.naplnObce(vektorObce);
    hierar = plnic.getHierar();
    //ds::amt::Hierarchy<ds::amt::MultiWayExplicitHierarchyBlock<Data>>::PreOrderHierarchyIterator begin(&hierar, test);
    //uroven 1
    string str = "St";
    string typ = "obec";

    function<bool(const Data&)> startsWith = [&](const Data& d) { return d.startsWith(str); };
    function<bool(const Data&)> containsStr = [&](const Data& d) { return d.containsStr(str); };
    //function<void(const Data&)> insertFunc = [&](const Data& d) { filteredData.push_back(d); };
    function<bool(const Data&)> hasType = [&](const Data& d) { return d.hasType(typ); };
    
    function<void(const Data&)> plnicPred = [&](const Data& d) { vektorNaplneny.insertLast().data_=d; };
    //function<bool(const Data&)> triedHlasky = [&](const Data& d) { return d.containsStr(str); };
    std::function<bool(const Data&, const Data&)> triedAbeceda = [&](const Data& d, const Data& a) {
        std::locale loc("Slovak_Slovakia.1250");
        const std::collate<char>& collate = std::use_facet<std::collate<char>>(loc);
        const char* pb1 = d.officialTitle.data();
        const char* pb2 = a.officialTitle.data();
        return collate.compare(pb1, pb1 + d.officialTitle.size(), pb2, pb2 + a.officialTitle.size()) < 0;
    };
    std::function<bool(const Data&, const Data&)> triedHlasky = [&](const Data& d, const Data& a) {
        return Algoritmus::pocitadloHlasiek(d.officialTitle) < Algoritmus::pocitadloHlasiek(a.officialTitle);
    };
    function<bool(const Data&)> trueLambda = [&](const Data& d) { return true; };
    cout << "ahoj, zacinas v slovensko kmeni, otvaram kraje v slovensku\n" << endl;
    int input = 0;
    auto aktualnyNode = hierar.accessRoot();
    typ = "kraj";
    while (input != -1) {

        ds::amt::Hierarchy<ds::amt::MultiWayExplicitHierarchyBlock<Data>>::PreOrderHierarchyIterator begin2(&hierar, aktualnyNode);
        cout << "--1 vyssie, 2 dole,3 containsStr,4 startsStr,5 hasType,6-podlaHlasiek, 7-podlaAbecedy--\n";
        vynulujStrukturu(vektorNaplneny);
        Algoritmus::filterPlnic(++begin2, hierar.end(), hasType, plnicPred);
        vypisStrukturu(vektorNaplneny);
        cin >> input;
        int index = 0;
        switch (input) {
        case 1:
            if (hierar.accessParent(*aktualnyNode) == nullptr) {
                cout << "viac sa neda ist hore" << endl;
                break;
            }
            typ = aktualnyNode->data_.type;
            aktualnyNode = hierar.accessParent(*aktualnyNode);

            break;


        case 2:





            cout << "vyber index";

            cin >> index;
            if (hierar.accessSon(*aktualnyNode, index)->sons_->isEmpty()) {
                cout << "nema synov" << endl;
                break;
            }
            aktualnyNode = hierar.accessSon(*aktualnyNode, index);

            typ = aktualnyNode->sons_->accessFirst()->data_->data_.type;

            break;




        case 3:
            cout << "co vyhladat?" << endl;
            cin >> str;
            Algoritmus::filterPlnic(++begin2, hierar.end(), containsStr, plnicPred);
            
            //TriediaciAlgoritmus::tried(vektorNaplneny, triedAbeceda);
            vypisStrukturu(vektorNaplneny);
            
            cout << "potvrd vysledok";
            
            cin >> str;
            break;

        case 4:
            cout << "co vyhladat?" << endl;
            cin >> str;
            Algoritmus::filterPlnic(++begin2, hierar.end(), startsWith, plnicPred);

            //TriediaciAlgoritmus::tried(vektorNaplneny, triedAbeceda);
            vypisStrukturu(vektorNaplneny);
            vynulujStrukturu(vektorNaplneny);
            cout << "potvrd vysledok";
            cin >> str;
            break;


        case 5:
            cout << "co vyhladat za typ ? okres,obec,kraj" << endl;
            cin >> typ;
            Algoritmus::filterPlnic(++begin2, hierar.end(), hasType, plnicPred);

            //TriediaciAlgoritmus::tried(vektorNaplneny, triedAbeceda);
            vypisStrukturu(vektorNaplneny);
            vynulujStrukturu(vektorNaplneny);
            cout << "vratit sa k nefiltrovanemu"<<endl;
            typ = aktualnyNode->sons_->accessFirst()->data_->data_.type;
            cin >> str;
            break;



        case 6:
            cout << "sortujemPodlaHlasok" << endl;
            
            cin >> str;
            //Algoritmus::filterPlnic(++begin2, hierar.end(), trueLambda, plnicPred);

            TriediaciAlgoritmus::tried(vektorNaplneny, triedHlasky);
            vypisStrukturu(vektorNaplneny);
            vynulujStrukturu(vektorNaplneny);
            cout << "vratit sa k nefiltrovanemu" << endl;
            typ = aktualnyNode->sons_->accessFirst()->data_->data_.type;
            cin >> str;
            break;



        case 7:
            cout << "sortujemPodlaAbecedy" << endl;
           
            //Algoritmus::filterPlnic(++begin2, hierar.end(), true, plnicPred);

            TriediaciAlgoritmus::tried(vektorNaplneny, triedAbeceda);
            vypisStrukturu(vektorNaplneny);
            vynulujStrukturu(vektorNaplneny);
            cout << "vratit sa k nefiltrovanemu" << endl;
            typ = aktualnyNode->sons_->accessFirst()->data_->data_.type;
            cin >> str;
            break;

        default:
            break;
        }


    }
    return 0;
}

void uroven4::vypisStrukturu(strukturaData& struktura)
{
    int pocitadlo = 0;
    for (Data data : struktura) {
        cout << "INDEX:" << pocitadlo <<"  " << data.toString();
        pocitadlo++;
    }
}

void uroven4::vynulujStrukturu(strukturaData& struktura)
{
    struktura.clear();
    
}
