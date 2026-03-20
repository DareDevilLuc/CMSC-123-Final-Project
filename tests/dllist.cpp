#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/dllist.h"

using namespace std;
using namespace chrono;

int main(){
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    // Table header
    cout << left << setw(12) << "ListSize"
         << setw(20) << "Avg AddEnd (us)"
         << setw(20) << "Avg RemoveEnd (us)"
         << setw(20) << "Avg Add0 (us)"
         << setw(20) << "Avg Remove0 (us)" << endl;
    cout << string(92, '-') << endl;

    for (int n : sizes) {
        double avgAddEnd, avgRemoveEnd, avgAddFront, avgRemoveFront;

        // --- Benchmark add at end (i = size) ---
        {
            DLList<int> list;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.add(list.size(), i);
            auto end = high_resolution_clock::now();
            avgAddEnd = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark remove at end (i = size-1) ---
        {
            DLList<int> list;
            for (int i = 0; i < n; i++) list.add(list.size(), i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.remove(list.size() - 1);
            auto end = high_resolution_clock::now();
            avgRemoveEnd = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark add at index 0 (front) ---
        {
            DLList<int> list;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.add(0, i);
            auto end = high_resolution_clock::now();
            avgAddFront = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark remove at index 0 (front) ---
        {
            DLList<int> list;
            for (int i = 0; i < n; i++) list.add(list.size(), i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) list.remove(0);
            auto end = high_resolution_clock::now();
            avgRemoveFront = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // Print results
        cout << left << setw(12) << n
             << setw(20) << fixed << setprecision(3) << avgAddEnd
             << setw(20) << fixed << setprecision(3) << avgRemoveEnd
             << setw(20) << fixed << setprecision(3) << avgAddFront
             << setw(20) << fixed << setprecision(3) << avgRemoveFront
             << endl;
    }

    return 0;
}