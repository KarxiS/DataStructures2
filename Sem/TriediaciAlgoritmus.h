#include <libds/adt/sorts.h>
#include <string>
#pragma once
class TriediaciAlgoritmus {
public:
    template<typename T, typename Comparator>
    void static inline tried(ds::amt::ImplicitSequence<T>& is, Comparator comp) {
        ds::adt::QuickSort<T> quickSort;
        quickSort.sort(is, comp);
    }

    
};


