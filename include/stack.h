#pragma once
#include <cstddef>

template <typename T>
class Stack{ //A stack follows the First-In, Last-Out (FILO) principle.
    public:
        virtual void push(const T& x) = 0;  //Adds a new element to the top of the stack.
        virtual T pop() = 0; //Removes and returns the top element from the stack and size decreases by 1.
        virtual T top() const = 0; //Returns (but does not remove) the value of the top element without removing it.
        virtual size_t size() const = 0; //Return the number of elements in the stack.
};