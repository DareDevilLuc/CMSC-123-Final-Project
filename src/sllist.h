#pragma once

#include "../include/linkedlistnode.h"

template <typename T>
class SLList {

    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        int size = 0;

    public:

        ~SLList(){
            while (size > 0) pop();
        }

        bool find(T x){
            Node<T> *currentNode = head;
            
            while(currentNode != nullptr){
                if(currentNode->value == x){
                    return true;
                }
                currentNode = currentNode->next;
            }
            return false;
        }

        void push(T x){
            Node<T> *newNode = new Node<T>;
            newNode->value = x;

            if(size == 0){
                head = newNode;
                tail = newNode;
                size++;
                return;
            }

            newNode->next = head;
            head = newNode;
            size++;
        }

        void add(T x){
            Node<T> *newNode = new Node<T>;
            newNode->value = x;

            if(size == 0){
                head = newNode;
                tail = newNode;
                size++;
                return;
            }

            tail->next = newNode;
            tail = newNode;
            size++;
        }

        void pop(){
            if(size == 0){
                return;
            }


            Node<T> *toRemove = head;

            if(size == 1){
                tail = nullptr;
                head = nullptr;
                delete toRemove;
                size--;
                return;
            }

            head = head->next;

            delete toRemove;
            size--;
            return;
        }

        void remove(T x){
            if(size == 0){
                return;
            }

            Node<T> *current = head;
            if(current->value == x){
                pop();
                return;
            }

            while(current->next != nullptr){
                if(current->next->value == x){
                    Node<T> *toRemove = current->next;
                    current->next = current->next->next;
                    if(toRemove == tail){
                        tail = current;
                    }
                    delete toRemove;
                    size--;
                    return;
                }
                current = current->next;
            }
            return;
        }

};

