#pragma once

template <typename T>
struct Node{
    T value = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};