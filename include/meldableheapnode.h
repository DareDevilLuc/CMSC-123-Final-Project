#pragma once

#include <cstddef>

template <typename T>
struct Node{
    T value;
    Node *left;
    Node *right;
    Node *parent;

    Node(T v){
        value = v;
        left = nullptr;
        right = nullptr;
    }

};
