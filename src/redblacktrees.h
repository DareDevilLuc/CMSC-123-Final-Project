
#pragma once
#include "../include/sset.h"

template <typename T>
class RedBlackTree : public SortedSet<T> {
    static const bool RED = true, BLACK = false;

    struct Node {
        T data;
        bool color;
        Node *left, *right, *parent;
        Node(T val) : data(val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root = nullptr;
    int count  = 0;

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;
        y->parent = x->parent;
        if      (!x->parent)          root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else                           x->parent->right = y;
        y->left = x; x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if      (!x->parent)           root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else                            x->parent->left = y;
        y->right = x; x->parent = y;
    }

    void fixInsert(Node* z) {
        while (z->parent && z->parent->color == RED) {
            bool left = (z->parent == z->parent->parent->left);
            Node* uncle = left ? z->parent->parent->right : z->parent->parent->left;
            if (uncle && uncle->color == RED) {
                z->parent->color = uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == (left ? z->parent->right : z->parent->left)) {
                    z = z->parent;
                    left ? rotateLeft(z) : rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left ? rotateRight(z->parent->parent) : rotateLeft(z->parent->parent);
            }
        }
        root->color = BLACK;
    }

    void transplant(Node* u, Node* v) {
        if      (!u->parent)           root = v;
        else if (u == u->parent->left)  u->parent->left = v;
        else                            u->parent->right = v;
        if (v) v->parent = u->parent;
    }

    void fixRemove(Node* x, Node* xp) {
        while (x != root && (!x || x->color == BLACK)) {
            bool left = (x == (xp ? xp->left : nullptr));
            Node* w = left ? xp->right : xp->left;
            if (w && w->color == RED) {
                w->color = BLACK; xp->color = RED;
                left ? rotateLeft(xp) : rotateRight(xp);
                w = left ? xp->right : xp->left;
            }
            if ((!w || !w->left  || w->left->color  == BLACK) &&
                (!w || !w->right || w->right->color == BLACK)) {
                if (w) w->color = RED;
                x = xp; xp = x->parent;
            } else {
                if (left ? (!w || !w->right || w->right->color == BLACK)
                         : (!w || !w->left  || w->left->color  == BLACK)) {
                    if (w) { (left ? w->left : w->right) ? (left ? w->left->color = BLACK : (w->right->color = BLACK, 0)) : 0; w->color = RED; }
                    if (w) left ? rotateRight(w) : rotateLeft(w);
                    w = left ? xp->right : xp->left;
                }
                if (w) w->color = xp->color;
                xp->color = BLACK;
                if (w && (left ? w->right : w->left)) (left ? w->right : w->left)->color = BLACK;
                left ? rotateLeft(xp) : rotateRight(xp);
                x = root;
            }
        }
        if (x) x->color = BLACK;
    }

    Node* minimum(Node* n) const { while (n->left) n = n->left; return n; }

    void destroy(Node* n) { if (!n) return; destroy(n->left); destroy(n->right); delete n; }

public:
    RedBlackTree() = default;
    ~RedBlackTree() { destroy(root); }

    bool add(T x) override {
        Node* p = nullptr; Node* cur = root;
        while (cur) {
            p = cur;
            if      (x < cur->data) cur = cur->left;
            else if (x > cur->data) cur = cur->right;
            else    return false;
        }
        Node* z = new Node(x); z->parent = p;
        if      (!p)           root = z;
        else if (x < p->data)  p->left = z;
        else                   p->right = z;
        count++; fixInsert(z); return true;
    }

    bool remove(T x) override {
        Node* z = root;
        while (z) {
            if      (x < z->data) z = z->left;
            else if (x > z->data) z = z->right;
            else    break;
        }
        if (!z) return false;

        Node* y = z; bool yColor = y->color;
        Node* fix = nullptr; Node* fixp = nullptr;

        if (!z->left)  { fix = z->right; fixp = z->parent; transplant(z, z->right); }
        else if (!z->right) { fix = z->left; fixp = z->parent; transplant(z, z->left); }
        else {
            y = minimum(z->right); yColor = y->color; fix = y->right;
            fixp = (y->parent == z) ? y : y->parent;
            if (y->parent != z) { transplant(y, y->right); y->right = z->right; y->right->parent = y; }
            transplant(z, y); y->left = z->left; y->left->parent = y; y->color = z->color;
        }
        delete z; count--;
        if (yColor == BLACK) fixRemove(fix, fixp);
        return true;
    }

    bool hasElement(T x) override {
        Node* cur = root;
        while (cur) {
            if      (x < cur->data) cur = cur->left;
            else if (x > cur->data) cur = cur->right;
            else    return true;
        }
        return false;
    }

    int size() const override { return count; }
};