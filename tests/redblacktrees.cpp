
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/redblacktrees.h"

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << left << setw(12) << "TreeSize"
         << setw(18) << "Avg add (us)"
         << setw(18) << "Avg remove (us)"
         << setw(18) << "Avg hasElement (us)" << endl;
    cout << string(66, '-') << endl;

    for (int n : sizes) {
        double avgAdd, avgRemove, avgHasElement;

        // --- Benchmark add ---
        {
            RedBlackTree<int> t;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) t.add(i);
            auto end = high_resolution_clock::now();
            avgAdd = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark hasElement ---
        {
            RedBlackTree<int> t;
            for (int i = 0; i < n; i++) t.add(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) t.hasElement(i);
            auto end = high_resolution_clock::now();
            avgHasElement = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark remove ---
        {
            RedBlackTree<int> t;
            for (int i = 0; i < n; i++) t.add(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) t.remove(i);
            auto end = high_resolution_clock::now();
            avgRemove = duration_cast<microseconds>(end - start).count() / double(n);
        }

        cout << left << setw(12) << n
             << setw(18) << fixed << setprecision(3) << avgAdd
             << setw(18) << fixed << setprecision(3) << avgRemove
             << setw(18) << fixed << setprecision(3) << avgHasElement
             << endl;
    }

    return 0;
}