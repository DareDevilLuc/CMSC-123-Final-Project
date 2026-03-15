#include <iostream>
#include <vector>
#include <chrono>
#include "../src/sllist.h"
using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    for (int n : sizes) {
        cout << "Testing list with " << n << " elements" << endl;

        // --- Benchmark push ---
        {
            SLList<int> list;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.push(i);
            auto end = high_resolution_clock::now();
            cout << "Push: " << duration_cast<microseconds>(end - start).count() << " us" << endl;
        }

        // --- Benchmark add ---
        {
            SLList<int> list;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.add(i);
            auto end = high_resolution_clock::now();
            cout << "Add: " << duration_cast<microseconds>(end - start).count() << " us" << endl;
        }

        // --- Benchmark pop (pre-fill, then time pops only) ---
        {
            SLList<int> list;
            for (int i = 0; i < n; i++) list.push(i); // fill, not timed
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.pop();
            auto end = high_resolution_clock::now();
            cout << "Pop: " << duration_cast<microseconds>(end - start).count() << " us" << endl;
        }

        cout << "----------------------------------------" << endl;
    }
    return 0;
}