#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/skiplist.h"

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << left << setw(12) << "ListSize"
         << setw(18) << "Avg add (us)"
         << setw(18) << "Avg remove (us)"
         << setw(18) << "Avg hasElement (us)" << endl;
    cout << string(66, '-') << endl;

    for (int n : sizes) {
        double avgAdd, avgRemove, avgContains;

        // --- Benchmark add ---
        {
            SkipList<int> sl;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) sl.add(i);
            auto end = high_resolution_clock::now();
            avgAdd = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark contains ---
        {
            SkipList<int> sl;
            for (int i = 0; i < n; i++) sl.add(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) sl.hasElement(i);
            auto end = high_resolution_clock::now();
            avgContains = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark remove ---
        {
            SkipList<int> sl;
            for (int i = 0; i < n; i++) sl.add(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) sl.remove(i);
            auto end = high_resolution_clock::now();
            avgRemove = duration_cast<microseconds>(end - start).count() / double(n);
        }

        cout << left << setw(12) << n
             << setw(18) << fixed << setprecision(3) << avgAdd
             << setw(18) << fixed << setprecision(3) << avgRemove
             << setw(18) << fixed << setprecision(3) << avgContains
             << endl;
    }

    return 0;
}