#pragma once
#include "../include/sset.h"
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
class SkipList : public SortedSet<T> {
private:
    struct Node {
        T data;
        std::vector<Node*> forward;
        Node(T val, int lvl) : data(val), forward(lvl + 1, nullptr) {}
    };

    Node* head;
    int   maxHeight;
    float prob;
    int   count;

    int randomLevel() {
        int lvl = 0;
        while ((static_cast<float>(rand()) / RAND_MAX) < prob && lvl < maxHeight)
            lvl++;
        return lvl;
    }

public:
    SkipList(int maxLvl = 16, float p = 0.5f) : maxHeight(maxLvl), prob(p), count(0) {
        srand(static_cast<unsigned>(time(0)));
        head = new Node(T(), maxHeight);
    }

    ~SkipList() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->forward[0];
            delete tmp;
        }
    }

    bool hasElement(T x) override {
        Node* cur = head;
        for (int i = maxHeight; i >= 0; i--)
            while (cur->forward[i] && cur->forward[i]->data < x)
                cur = cur->forward[i];
        cur = cur->forward[0];
        return cur && cur->data == x;
    }

    bool add(T x) override {
        std::vector<Node*> predecessors(maxHeight + 1, nullptr);
        Node* cur = head;
        for (int i = maxHeight; i >= 0; i--) {
            while (cur->forward[i] && cur->forward[i]->data < x)
                cur = cur->forward[i];
            predecessors[i] = cur;
        }
        cur = cur->forward[0];
        if (cur && cur->data == x) return false;

        int lvl = randomLevel();
        Node* node = new Node(x, lvl);
        for (int i = 0; i <= lvl; i++) {
            node->forward[i]            = predecessors[i]->forward[i];
            predecessors[i]->forward[i] = node;
        }
        count++;
        return true;
    }

    bool remove(T x) override {
        std::vector<Node*> predecessors(maxHeight + 1, nullptr);
        Node* cur = head;
        for (int i = maxHeight; i >= 0; i--) {
            while (cur->forward[i] && cur->forward[i]->data < x)
                cur = cur->forward[i];
            predecessors[i] = cur;
        }
        cur = cur->forward[0];
        if (!cur || cur->data != x) return false;

        for (int i = 0; i <= maxHeight; i++) {
            if (predecessors[i]->forward[i] != cur) break;
            predecessors[i]->forward[i] = cur->forward[i];
        }
        delete cur;
        count--;
        return true;
    }

    int size() const override { return count; }
};