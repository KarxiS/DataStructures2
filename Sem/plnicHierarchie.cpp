#include "plnicHierarchie.h"

plnicHierarchie::plnicHierarchie(ds::amt::MultiWayExplicitHierarchy<Data>& hierarchia) : hierarchiaLocal(hierarchia) {
    
}

void plnicHierarchie::naplnKraje(ds::amt::ImplicitSequence<Data> vektorKraje)
{
    auto& hierar = this->hierarchiaLocal;
    auto& slovenskoNode = *hierar.accessRoot();
    for (Data kraj : vektorKraje) {

        
        auto& root = hierar.emplaceSon(*hierar.accessRoot(), hierar.degree(slovenskoNode));
        root.data_ = kraj;
        //root.parent_ = hierar.accessRoot();
        //auto& data =root.data_;

    }

}

void plnicHierarchie::naplnOkresy(ds::amt::ImplicitSequence<Data> vektorOkresy)
{
    auto& hierar = this->hierarchiaLocal;
    auto& slovenskoNode = *hierar.accessRoot();

    size_t pocitadlo = 0;

    for (Data okres : vektorOkresy) {

        size_t zaciatocneCislo = stoi(okres.note.substr(0, 1));
        if (zaciatocneCislo == 0) {
            continue;
        }
        const auto najdenySyn = hierar.accessSon(slovenskoNode, zaciatocneCislo - 1);
        hierar.emplaceSon(*najdenySyn, hierar.degree(*najdenySyn)).data_ = okres;
        pocitadlo++;
    }
}

void plnicHierarchie::naplnObce(ds::amt::ImplicitSequence<Data> vektorObce)
{
    auto& hierar = this->hierarchiaLocal;
    auto& slovenskoNode = *hierar.accessRoot();


    string kodOkresuZaloha = "";
    string kodKrajuZaloha = "";
    int pocitadloOkresu = 0;
    int pocitadloKraja = 0;
    for (Data obec : vektorObce) {


        string kodKrajuLoop = obec.kod.substr(3, 2);
        if (kodKrajuLoop != kodKrajuZaloha) {
            pocitadloKraja++;
            pocitadloOkresu = 0;
            kodKrajuZaloha = kodKrajuLoop;

        }


        string kodOkresuLoop = obec.kod.substr(3, 3);
        if (kodOkresuLoop != kodOkresuZaloha) {
            pocitadloOkresu++;
            kodOkresuZaloha = kodOkresuLoop;

        }
        const auto najdenyKraj = hierar.accessSon(slovenskoNode, pocitadloKraja - 1);

        const auto najdenyOkres = hierar.accessSon(*najdenyKraj, pocitadloOkresu - 1);
        auto& synDebug = hierar.emplaceSon(*najdenyOkres, hierar.degree(*najdenyOkres)).data_ = obec;

    }
}

ds::amt::MultiWayExplicitHierarchy<Data>& plnicHierarchie::getHierar() {
    return hierarchiaLocal;
}
