//This is a FIFO Queue (linked list)
#pragma once
#include "../include/queue.h"
#include "../include/linkedlistnode.h"
#include <cstddef>
#include <stdexcept>

template <typename T>

class LLQueue : public Queue<T>{
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        size_t n = 0;

    public:
    ~LLQueue(){
        while(head != nullptr) {
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        }
        tail = nullptr;
        n = 0;
        }

    void push(const T& x) override{
        Node<T> *newNode = new Node<T>;
        newNode->value = x;
        newNode->next = nullptr;

        if(n == 0){
            head = tail = newNode;
            n++;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        n++;
    }

    T pop() override{
        if(n == 0) throw std::out_of_range("Queue is empty");

        Node<T> *backUp = head;

        T result = backUp->value;
        head = head->next;

        if(head == nullptr) tail = nullptr;

        delete backUp;
        n--;
        return result;
    }

    T peek() const override{
        if(n == 0) throw std::out_of_range("Queue is empty");
        return head->value;
    }

    size_t size() const override{
        return this->n;
    }

    bool isEmpty() const override{
        if(n == 0){ return true; }
        else{ return false; }
    }

};