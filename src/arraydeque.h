#include "../include/array.h"
#include "../include/deque.h"
#include "../include/list.h"
#include <algorithm>

template <typename T>
class ArrayDeque : public Deque<T>, public List<T>{
    private:
        array<T> arr;
        int j;
        int size;
    

    public:
        ArrayDeque() : a(10) {}
};
