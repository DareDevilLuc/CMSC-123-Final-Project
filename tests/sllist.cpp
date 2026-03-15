#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/sllist.h"

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    // Table header
    cout << left << setw(10) << "ListSize"
         << setw(18) << "Avg Push (us)"
         << setw(18) << "Avg Add (us)"
         << setw(18) << "Avg Pop (us)" << endl;
    cout << string(64, '-') << endl;

    for (int n : sizes) {
        double avgPush, avgAdd, avgPop;

        // --- Benchmark push ---
        {
            SLList<int> list;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.push(i);
            auto end = high_resolution_clock::now();
            avgPush = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark add ---
        {
            SLList<int> list;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.add(i);
            auto end = high_resolution_clock::now();
            avgAdd = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark pop ---
        {
            SLList<int> list;
            for (int i = 0; i < n; i++) list.push(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.pop();
            auto end = high_resolution_clock::now();
            avgPop = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // Print results in table format with decimals
        cout << left << setw(10) << n
             << setw(18) << fixed << setprecision(3) << avgPush
             << setw(18) << fixed << setprecision(3) << avgAdd
             << setw(18) << fixed << setprecision(3) << avgPop
             << endl;
    }

    return 0;
}