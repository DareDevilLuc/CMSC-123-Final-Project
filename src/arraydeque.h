#include "../include/array.h"
#include "../include/deque.h"
#include "../include/list.h"
#include <algorithm>

template <typename T>
class ArrayDeque : public Deque<T>, public List<T> {
private:
    array<T> arr;
    int j = 0;         // start index
    int sizeN = 0;     // number of elements

    void resize() {
        array<T> b(std::max(1, 2 * sizeN));
        for (int k = 0; k < sizeN; k++) {
            b[k] = arr[(j + k) % arr.length];
        }
        arr = b;
        j = 0;
    }

    T get(const size_t i) const override {
        return arr[(j + i) % arr.length];
    }

    T set(const size_t i, const T& x) override {
        T y = arr[(j + i) % arr.length];
        arr[(j + i) % arr.length] = x;
        return y;
    }

    void addAll(int i, List<T>& d) {
        int numElements = d.size();
        if (numElements == 0) return;

        while (sizeN + numElements > arr.length) resize();

        if (i < sizeN / 2) {
            // shift left side
            j = (j - numElements + arr.length) % arr.length;
            for (int k = 0; k < i; k++) {
                arr[(j + k) % arr.length] = arr[(j + k + numElements) % arr.length];
            }
        } else {
            // shift right side
            for (int k = sizeN - 1; k >= i; k--) {
                arr[(j + k + numElements) % arr.length] = arr[(j + k) % arr.length];
            }
        }

        for (int k = 0; k < numElements; k++) {
            arr[(j + i + k) % arr.length] = d.get(k);
        }

        sizeN += numElements;
    }

    void add(const size_t i, const T& x) override {
        if (sizeN + 1 > arr.length) resize();

        if (i < sizeN / 2) {
            j = (j == 0) ? arr.length - 1 : j - 1;
            for (int k = 0; k < i; k++) {
                arr[(j + k) % arr.length] = arr[(j + k + 1) % arr.length];
            }
        } else {
            for (int k = sizeN; k > i; k--) {
                arr[(j + k) % arr.length] = arr[(j + k - 1) % arr.length];
            }
        }

        arr[(j + i) % arr.length] = x;
        sizeN++;
    }

    T remove(const size_t i) override {
        T x = arr[(j + i) % arr.length];

        if (i < sizeN / 2) {
            for (int k = i; k > 0; k--) {
                arr[(j + k) % arr.length] = arr[(j + k - 1) % arr.length];
            }
            j = (j + 1) % arr.length;
        } else {
            for (int k = i; k < sizeN - 1; k++) {
                arr[(j + k) % arr.length] = arr[(j + k + 1) % arr.length];
            }
        }

        sizeN--;
        if (3 * sizeN < arr.length) resize();

        return x;
    }

public:
    ArrayDeque() : arr(10) {}

    void addFirst(const T& x) override {
        add(0, x);
    }

    void addLast(const T& x) override {
        add(sizeN, x);
    }

    T removeFirst() override {
        return remove(0);
    }

    T removeLast() override {
        return remove(sizeN - 1);
    }

    const T peekFirst() const override {
        return get(0);
    }

    const T peekLast() const override {
        return get(sizeN - 1);
    }

    bool isEmpty() const override {
        return sizeN == 0;
    }

    void clear() override {
        while (!isEmpty()) removeLast();
    }

    size_t size() const override {
        return sizeN;
    }
};