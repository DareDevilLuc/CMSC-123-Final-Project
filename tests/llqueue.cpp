#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/llqueue.h"

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    // Table header
    cout << left << setw(12) << "QueueSize"
         << setw(20) << "Avg Push (us)"
         << setw(20) << "Avg Pop (us)"
         << setw(20) << "Avg Peek (us)"
         << setw(20) << "Mixed Ops (us)" << endl;
    cout << string(92, '-') << endl;

    for (int n : sizes) {
        double avgPush, avgPop, avgPeek, avgMixed;

        // --- Benchmark push (enqueue) ---
        {
            LLQueue<int> q;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) q.push(i);
            auto end = high_resolution_clock::now();
            avgPush = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark pop (dequeue) ---
        {
            LLQueue<int> q;
            for (int i = 0; i < n; i++) q.push(i); // pre-fill

            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) q.pop();
            auto end = high_resolution_clock::now();

            avgPop = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark peek ---
        {
            LLQueue<int> q;
            for (int i = 0; i < n; i++) q.push(i);

            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) q.peek();
            auto end = high_resolution_clock::now();

            avgPeek = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Mixed operations (realistic queue usage) ---
        {
            LLQueue<int> q;

            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) {
                q.push(i);
                if (i % 2 == 0) q.pop();
            }
            auto end = high_resolution_clock::now();

            avgMixed = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // Print results
        cout << left << setw(12) << n
             << setw(20) << fixed << setprecision(3) << avgPush
             << setw(20) << fixed << setprecision(3) << avgPop
             << setw(20) << fixed << setprecision(3) << avgPeek
             << setw(20) << fixed << setprecision(3) << avgMixed
             << endl;
    }

    return 0;
}