#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <random>
#include "../src/chainedhashtable.h"

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    cout << left << setw(12) << "TableSize"
         << setw(20) << "Avg Insert (us)"
         << setw(20) << "Avg isPresent (us)"
         << setw(20) << "Avg Remove (us)" << endl;

    cout << string(72, '-') << endl;

    for (int n : sizes) {
        double avgInsert, avgIsPresent, avgRemove;

        // Table size ~ n for low load factor
        int tableSize = n;

        // --- Benchmark insert ---
        {
            ChainedHashTable<int> ht(tableSize);

            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) {
                ht.insert(i);
            }
            auto end = high_resolution_clock::now();

            avgInsert = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark isPresent ---
        {
            ChainedHashTable<int> ht(tableSize);
            for (int i = 0; i < n; i++) ht.insert(i);

            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) {
                ht.isPresent(i);
            }
            auto end = high_resolution_clock::now();

            avgIsPresent = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark remove ---
        {
            ChainedHashTable<int> ht(tableSize);
            vector<int> values;

            for (int i = 0; i < n; i++) {
                ht.insert(i);
                values.push_back(i);
            }

            // Shuffle values to remove in random order
            random_device rd;
            mt19937 g(rd());
            shuffle(values.begin(), values.end(), g);

            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) {
                ht.removeElement(values[i]);
            }
            auto end = high_resolution_clock::now();

            avgRemove = duration_cast<microseconds>(end - start).count() / double(n);
        }

        cout << left << setw(12) << n
             << setw(20) << fixed << setprecision(3) << avgInsert
             << setw(20) << fixed << setprecision(3) << avgIsPresent
             << setw(20) << fixed << setprecision(3) << avgRemove
             << endl;
    }

    return 0;
}