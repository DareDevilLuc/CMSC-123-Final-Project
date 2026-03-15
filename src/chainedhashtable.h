#pragma once

#include "../include/list.h"
#include "../include/array.h"
#include <functional>

template <typename T>
class ChainedHashTable {
    private:
        array<List<T>> table;
        int numOfElements;

        int computeHashIndex(T x){
            return std::hash<T>{}(x) % numOfElements;
        }

    public:
        ChainedHashTable(int i) : numOfElements(i) {}
};
