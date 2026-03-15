#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>
#include <iomanip>
#include "../src/meldableheap.h"

using namespace std;
using namespace chrono;

int main() {
    // Heap sizes to test
    vector<int> heapSizes = {1000, 5000, 10000, 50000, 100000};
    const int trials = 30;  // number of runs per heap size to average

    // Random number generator
    mt19937 gen(random_device{}());
    uniform_int_distribution<int> dist(1, 1000000);

    // Table header
    cout << left << setw(10) << "HeapSize"
         << setw(12) << "log2(N)"
         << setw(18) << "Avg Insert (us)"
         << setw(18) << "Avg Delete (us)" << endl;
    cout << string(58, '-') << endl;

    for(int N : heapSizes) {
        double totalAvgInsert = 0;
        double totalAvgDelete = 0;

        for(int t = 0; t < trials; t++) {
            MeldableHeap<int> minHeap(MIN_HEAP);

            // Generate random numbers
            vector<int> numbers(N);
            for(int i = 0; i < N; i++)
                numbers[i] = dist(gen);

            // --- Benchmark insertions ---
            auto start = high_resolution_clock::now();
            for(int x : numbers)
                minHeap.insert(x);
            auto end = high_resolution_clock::now();
            double avgInsertUS = duration_cast<microseconds>(end - start).count() / double(N);
            totalAvgInsert += avgInsertUS;

            // --- Benchmark deletions ---
            start = high_resolution_clock::now();
            while(!minHeap.isEmpty())
                minHeap.deleteTop();
            end = high_resolution_clock::now();
            double avgDeleteUS = duration_cast<microseconds>(end - start).count() / double(N);
            totalAvgDelete += avgDeleteUS;
        }

        // Compute average over trials
        double avgInsert = totalAvgInsert / trials;
        double avgDelete = totalAvgDelete / trials;

        // Print results in readable table
        cout << left << setw(10) << N
             << setw(12) << fixed << setprecision(2) << log2(N)
             << setw(18) << fixed << setprecision(3) << avgInsert
             << setw(18) << fixed << setprecision(3) << avgDelete
             << endl;
    }

    return 0;
}