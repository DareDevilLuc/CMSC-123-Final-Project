#include <iostream>
#include "../src/meldableheap.h"

int main(){

    MeldableHeap<int> test;

    for(int i = 1; i <= 5; i++){
        int randomMult = rand() % 4;
        test.insert(i*randomMult);
    }

    test.print();
}