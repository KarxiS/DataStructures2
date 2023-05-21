#pragma once
#include "Data.h"
#include <vector>
#include <iostream>
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
};



