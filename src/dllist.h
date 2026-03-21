//List ADT using Doubly Linked List
#pragma once

#include "../include/dlinkedlistnode.h"
#include "../include/list.h"
#include <cstddef>
#include <stdexcept>


template <typename T>
class DLList : public List<T>{
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        size_t n = 0;

    public:
        ~DLList(){
            while(head != nullptr){
                Node<T> *temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            n = 0;
        }

        void add(const size_t i, const T& x) override{
            if(i > n) throw std::out_of_range("Index out of bounds");

            Node<T> *add = new Node<T>;
            add->value = x;
            add->prev = nullptr;
            add->next = nullptr;

            if(i == 0){
                add->next = head;
                if(head != nullptr) head->prev = add;
                head = add;
                if(n == 0) tail = add;
            }
            else if(i == n){
                add->prev = tail;
                if(tail != nullptr) tail->next = add;
                tail = add;
                if(n == 0) head = add;
            }
            else{
                Node<T> *currentNode = head;
                for(int current = 0; current < i; current++) currentNode = currentNode->next;
                add->next = currentNode;
                add->prev = currentNode->prev;
                currentNode->prev->next = add;
                currentNode->prev = add;    
            }
            n++;
        }

        T remove(const size_t i) override{
            if(i >= n) throw std::out_of_range("Index out of bounds");
            
            Node<T> *target;
            if(i == 0){
                target = head;
                head = head->next;
                if(head != nullptr) head->prev = nullptr;
                if(n == 1) tail = nullptr;
            }
            else if(i == n - 1){
                target = tail;
                tail = tail->prev;
                if(tail != nullptr) tail->next = nullptr;
                if(n == 1) head = nullptr;
            }
            else{
                target = head;
                for(size_t j = 0; j < i; j++) target = target->next;

                target->prev->next = target->next;
                target->next->prev = target->prev;
            }

            T val = target->value;
            delete target;
            n--;

            return val;

        }

        T get(const size_t i) const override{
            if(i >= n) throw std::out_of_range("Index out of bounds");

            Node<T>* current = head;
            for(size_t j = 0; j < i; j++) current = current->next;

            return current->value;
        }

        T set(const size_t i, const T& x) override{
            if(i >= n) throw std::out_of_range("Index out of bounds");

            Node<T>* current = head;
            for(size_t j = 0; j < i; j++) current = current->next;

            T old = current->value;
            current->value = x;

            return old;
        }

        size_t size() const override{
            return n;
        }

};