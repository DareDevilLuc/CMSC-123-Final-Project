#pragma once

template <typename T>
class PriorityQueue{
    public:
        virtual void insert(T x) = 0;
        virtual T findMin() = 0;
        virtual T deleteMin() = 0;
        virtual bool isEmpty() = 0;
};