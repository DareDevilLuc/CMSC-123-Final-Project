#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/arraydeque.h" 

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    // Table header
    cout << left << setw(10) << "DequeSize"
         << setw(18) << "Avg addFirst (us)"
         << setw(18) << "Avg addLast (us)"
         << setw(18) << "Avg removeFirst (us)"
         << setw(18) << "Avg removeLast (us)" << endl;
    cout << string(82, '-') << endl;

    for (int n : sizes) {
        double avgAddFirst, avgAddLast, avgRemoveFirst, avgRemoveLast;

        // --- Benchmark addFirst ---
        {
            ArrayDeque<int> dq;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) dq.addFirst(i);
            auto end = high_resolution_clock::now();
            avgAddFirst = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark addLast ---
        {
            ArrayDeque<int> dq;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) dq.addLast(i);
            auto end = high_resolution_clock::now();
            avgAddLast = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark removeFirst ---
        {
            ArrayDeque<int> dq;
            for (int i = 0; i < n; i++) dq.addLast(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) dq.removeFirst();
            auto end = high_resolution_clock::now();
            avgRemoveFirst = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark removeLast ---
        {
            ArrayDeque<int> dq;
            for (int i = 0; i < n; i++) dq.addLast(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) dq.removeLast();
            auto end = high_resolution_clock::now();
            avgRemoveLast = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // Print results in table format with decimals
        cout << left << setw(10) << n
             << setw(18) << fixed << setprecision(3) << avgAddFirst
             << setw(18) << fixed << setprecision(3) << avgAddLast
             << setw(18) << fixed << setprecision(3) << avgRemoveFirst
             << setw(18) << fixed << setprecision(3) << avgRemoveLast
             << endl;
    }

    return 0;
}
