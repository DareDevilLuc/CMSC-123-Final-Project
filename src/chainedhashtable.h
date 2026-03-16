#pragma once

#include "../include/list.h"
#include "../include/array.h"
#include "sllist.h"
#include <functional>

template <typename T>
class ChainedHashTable {
    private:
        array<SLList<T>> table;
        int numOfElements = 0;

        int computeHashIndex(T x){
            return std::hash<T>{}(x) % table.length;
        }

    public:
        
        ChainedHashTable(int i) : table(i) {}
};
