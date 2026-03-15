#pragma once

#include "../include/priorityqueue.h"
#include "../include/meldableheapnode.h"
#include <iostream>
#include <random>

using namespace std;

enum HeapType {
    MIN_HEAP = 0,
    MAX_HEAP = 1
};

template <typename T>
class MeldableHeap : public PriorityQueue<T>{
    private:
        Node<T> *root = nullptr;
        int size = 0;
        HeapType heap_type;

        Node<T> *meld(Node<T> *h1, Node<T> *h2){
            if(h1 == nullptr) return h2;
            if(h2 == nullptr) return h1;

            if(compare(h1->value, h2->value)) return meld(h2, h1);


            if(rand() % 2){
                h1->left = meld(h1->left, h2);
                if(h1->left != nullptr) h1->left->parent = h1;
            }
            else{
                h1->right = meld(h1->right, h2);
                if(h1->right != nullptr) h1->right->parent = h1;
            }

            return h1;

        };

        bool compare(T x, T y){
            if(heap_type == MIN_HEAP) return x > y;
            else return x < y;
        };

        void clear(Node<T> *node){
            if(node == nullptr) return;

            clear(node->left);
            clear(node->right);
            delete node;
        }

    public:

        MeldableHeap(HeapType t) : heap_type(t) {}

        ~MeldableHeap(){
            clear(root);
        }

        void insert(T x){
            Node<T> *newNode = new Node<T>(x);

            root = meld(root, newNode);
            root->parent = nullptr;
            size++;
        }

        T findTop(){
            return root->value;
        }

        T deleteTop(){
            T x = root->value;
            Node<T> *tmp = root;
            root = meld(root->left, root->right);

            delete tmp;
            if(root != nullptr) root->parent = nullptr;
            size--;

            return x;
        }

        bool isEmpty(){
            return size == 0;
        }

        // source :: https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c

        void printHeap(const string& prefix, Node<T>* node, bool isLeft) {
            if (node != nullptr) {
                cout << prefix;

                // choose the connector
                cout << (isLeft ? "├── " : "└── ");

                // print the node value
                cout << node->value << endl;

                // recurse on left and right children
                printHeap(prefix + (isLeft ? "│   " : "    "), node->left, true);
                printHeap(prefix + (isLeft ? "│   " : "    "), node->right, false);
            }
        }

        void print() {
            if (!root) {
                cout << "(empty heap)" << endl;
                return;
            }
            printHeap("", root, false);
        }
        
};