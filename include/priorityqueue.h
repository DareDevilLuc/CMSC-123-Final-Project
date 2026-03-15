#pragma once

template <typename T>
class PriorityQueue{
    public:
        virtual void insert(T x) = 0;
        virtual T findTop() = 0;
        virtual T deleteTop() = 0;
        virtual bool isEmpty() = 0;
};