#pragma once

#include "../include/array.h"
#include "../include/stack.h"
#include "../include/list.h"
#include <algorithm>
#include <cstddef>
#include <cassert>

template <typename T>
class ArrayStack : public Stack<T>, public List<T>{
    private:
        array<T> backingArray;
        int n;

    void resize(){
        array<T> b(std::max(2 * this->n, 1));
        for(int i = 0; i < this->n; i++){
            b[i] = this->backingArray[i];
        }
        this->backingArray = b;
    }

    public:

    ArrayStack() : backingArray(10), n(0){}

    ~ArrayStack(){}

    size_t size() const override{
        return this->n;
    }

    void add(const size_t i, const T& x) override{
        assert(i >= 0 && i <= this->n);
        if(this->n >= this->backingArray.length){
            resize();
        }

        for(int j = this->n; j > i; j--){
            this->backingArray[j] = this ->backingArray[j-1];

        }
        this->backingArray[i] = x;
        this->n++;
    }

    T remove(const size_t i) override{
        assert(i >= 0 && i < this->n);
        T result = this->backingArray[i];
        for(int j = i; j < n - 1; j++){
            this->backingArray[j] = this->backingArray[j+1];
        }
        this->n--;

        this->backingArray[this->n] = T{};

        if(this->backingArray.length >= 3 * this->n){
            this->resize();
        }
        return result;
    }

    T get(const size_t i) const override{
        assert(i >=0 && i < this->n);
        return this->backingArray[i];
    }

    T set(const size_t i, const T& x) override{
        assert(i >=0 && i < this->n);
        T y = this->backingArray[i];
        this->backingArray[i] = x;
        return y;
    }

    void push(const T& x) override{
        if(this->n >= this->backingArray.length){
            resize();
        }
        this->backingArray[n] = x;
        this->n++;
    }

    T pop() override{
        assert(n > 0);
        n--;
        T result = this->backingArray[n];
        this->backingArray[n] = T{};             
        if(this->backingArray.length >= 3 * n){
            resize();
        }
        return result;
    }

    T top() const override{
        assert(n > 0);
        return this->backingArray[this->n - 1];
    }
};