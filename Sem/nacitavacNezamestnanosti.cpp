#include "nacitavacNezamestnanosti.h"
#include <iostream>

nacitavacNezamestnanosti::nacitavacNezamestnanosti(std::string menoSuboru)
{
    handler.open(menoSuboru, ios::in);
    if (!handler.is_open()) {
        cout << "zly input" << endl;
        exit;

    }
    std::cout << "nacitavam novy subor:" << menoSuboru << endl;
}

void nacitavacNezamestnanosti::nacitajDoHierarchie(ds::amt::MultiWayExplicitHierarchy<Data>& hierarchia)
{


    string slovo;     
    auto aktualnyIter = hierarchia.begin();
       
        string riadok;
        getline(handler, riadok);
        while (getline(handler, riadok)) {
            stringstream s(riadok);
            vector<string> values;

            while (getline(s, slovo, ';')) {
                values.push_back(slovo);
            }
            if (values.size() == 3) {
                string kod = values[0];
                string officialTitle = values[1];
                string nezamestnanost = values[2];
                for (auto& it = aktualnyIter; it != hierarchia.end(); ++it) {
                    Data& data = it.operator*();
                    if (data.getKod() != kod) {
                        continue;
                    }
                    else {
                        data.setNezamestnanost(nezamestnanost);
                        aktualnyIter = it;
                        
                        break;
                    }


                
                }

                s.clear();
            }

            

        }
        







    }



