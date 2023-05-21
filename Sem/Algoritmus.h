#pragma once
#include "Data.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class Algoritmus {
public:


    template<typename OutputIt>
    static inline void vypisUdaje(const OutputIt& begin, const OutputIt& end) {
        for (auto it = begin; it != end; ++it) {
            OutputIt data = *it;
            cout << data.toString() << endl;
        }
    }


    template<typename Typ, typename Predikat>
    static inline void filter(const Typ& begin, const Typ& end, Predikat p) {
        size_t pocitadlo = 0;

        for (auto it = begin; it != end; ++it) {
            if (p(*it)) {
                Data data = *it;
                cout << "INDEX:" << pocitadlo << ".   ";
                std::cout << data.toString();
                pocitadlo++;
            }
        }

    }

    template<typename Typ, typename Predikat>
    static inline void filterPointer(const Typ& begin, const Typ& end, Predikat p) {
        size_t pocitadlo = 0;

        for (auto it = begin; it != end; ++it) {
            if (p(*it)) {
                Data* data = *it;
                cout << "INDEX:" << pocitadlo << ".   ";
                std::cout << data->toString();
                pocitadlo++;
            }
        }

    }


    template<typename Typ, typename Predikat, typename PredikatPlnic>
    static inline void filterPlnic(const Typ& begin, const Typ& end, Predikat p, PredikatPlnic plnic) {
        for (auto it = begin; it != end; ++it) {
            if (p(*it)) {
                plnic(*it);
            }
        }
    }


    static bool jeHlaska(std::string hlaska) {
        const std::string hlasky = "AÁÄEÉIÍOÓUÚYÝaáäeéiíoóuúyý";
        if (hlasky.find(hlaska) == std::string::npos) {
            return false;
        }
        else {
            return true;
        }
    }

    static int pocitadloHlasiek(const std::string& slovo) {
        return std::count_if(slovo.begin(), slovo.end(), [](char c) {
            return Algoritmus::jeHlaska(std::string(1, c));
            });
    }
};



