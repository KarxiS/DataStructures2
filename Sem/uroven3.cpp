#include "uroven3.h"
#include "Algoritmus.h"
#include "Nacitavac.h"
#include <libds/adt/table.h>
#include "Algoritmus.h"


auto uroven3::main() -> int
{
    initHeapMonitor();

    {
        Algoritmus algObce;
        //cout << "zadajte nazov suboru (obce.csv,kraje.csv,okresy.csv)" << endl;
        //string string1;
        //cin >> string1;
        string string1 = "kraje.csv";
        Nacitavac nacitavacKraje("kraje.csv");
        ds::amt::ImplicitSequence<Data*> vektorKraje = nacitavacKraje.dajDataSmernik();

        Nacitavac nacitavacOkresy("okresy.csv");
        ds::amt::ImplicitSequence<Data*> vektorOkresy = nacitavacOkresy.dajDataSmernik();

        Nacitavac nacitavacObce("obce.csv");
        ds::amt::ImplicitSequence<Data*> vektorObce = nacitavacObce.dajDataSmernik();

        ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>* tabulkaKraj =
            new ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>();

        ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>* tabulkaKObec =
            new ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>();

        ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>* tabulkaOkres =
            new ds::adt::SortedSequenceTable<std::string, ds::amt::ImplicitSequence<Data*>*>();




        this->naplnTabulku(tabulkaKraj, vektorKraje);
       

        this->naplnTabulku(tabulkaOkres, vektorOkresy);
        

       
        this->naplnTabulku(tabulkaKObec, vektorObce);
       
        string nazov = "";
        int input = 0;
        
        
        
        function<bool(const Data*)> containsStr = [&](const Data* d) {
            Data data = *d;
            return data.containsStr(nazov);

        };
        while (input!=-1) {


            cout << "zadaj nazov a typ(1-obec,2-okres,3-kraj)" << endl;
            cout << "nazov:" << endl;
            cin >> nazov;
            cout << "typ:" << endl;
            cin >> input;

            switch (input) {

            case(1): {




                auto* block = tabulkaKObec->findBlockWithKey(nazov);
                if (block == nullptr) {
                    cout << "zly kluc" << endl;
                }
                auto& seq = block->data_.data_;
                Algoritmus::filterPointer(seq->begin(), seq->end(), containsStr);
                break;
            }

            case(3): {





                auto* block = tabulkaKraj->findBlockWithKey(nazov);
                
                if (block == nullptr) {
                    cout << "zly kluc" << endl;
                }
                auto& seq = block->data_.data_;
                Algoritmus::filterPointer(seq->begin(), seq->end(), containsStr);
                break;
            }
                   break;
            case(2): {




                auto* block = tabulkaKraj->findBlockWithKey(nazov);
                if (block == nullptr) {
                    cout << "zly kluc" << endl;
                }
                auto& seq = block->data_.data_;
                Algoritmus::filterPointer(seq->begin(), seq->end(), containsStr);
                break;

            }
            default:
                break;
            };
        }
        
        return 0;
    }
}

   


uroven3::tabulkaSekvencii uroven3::naplnTabulku(tabulkaSekvencii tabulka, ds::amt::ImplicitSequence<Data*> sekvenciaObjektov) {
    
    for (auto& kraj : sekvenciaObjektov) {
        string officialName = kraj->getOffTitle();
        auto* blok = tabulka->findBlockWithKey(officialName);
        if (blok != nullptr) {
            auto& data = blok->data_;
            auto& sequence = data.data_;
            sequence->insertLast().data_ = kraj;

        }
        else {
            ds::amt::ImplicitSequence<Data*>* kraje = new ds::amt::ImplicitSequence<Data*>();
            kraje->insertLast().data_ = kraj;
            (*tabulka).insert(kraj->getOffTitle(), kraje);
        }
    }
   
    return tabulka;

}

uroven3::~uroven3()
{
    vektorKraje.clear();
    vektorObce.clear();
    vektorOkresy.clear();
    tabulkaKObec->clear();
    tabulkaOkres->clear();
    tabulkaKraj->clear();

}
