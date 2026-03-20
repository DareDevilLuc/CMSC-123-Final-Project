#pragma once

template <typename T>
struct Node{
    T value;
    Node *prev = nullptr;
    Node *next = nullptr;
};