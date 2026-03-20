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

        int computeHashIndex(const T &x){
            size_t hashValue = std::hash<T>{}(x) ;
            return hashValue % table.length;
        }

    public:

        ChainedHashTable(int i) : table(i) {}

        void insert(const T &x){
            int index = computeHashIndex(x);

            if(table[index].find(x)){
                return;
            }

            table[index].add(x);
            numOfElements++;
        }

        void removeElement(const T &x){
            int index = computeHashIndex(x);

            if(!table[index].find(x)){
                return;
            }

            table[index].remove(x);
            numOfElements--;
        }

        bool isPresent(const T &x){
            size_t index = computeHashIndex(x);
            return table[index].find(x);
        }
};
