#pragma once
#include <cstddef>

template <typename T>

class Queue{ //A queue follows the First-in, First-out (FIFO) principle
    public:
        virtual void push(const T& x) = 0; //Inserts a new element x at the rear (tail) of the queue
        virtual T pop() = 0; //Removes and returns the element from the front (head)
        virtual T peek() const = 0; //Returns the value at the front of the queue without removing it
        virtual size_t size() const = 0; //Returns the number of elements currently in the queue
        virtual bool isEmpty() const = 0; //True if queue is empty
};
