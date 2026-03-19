#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/arraystack.h"

using namespace std;
using namespace chrono;


int main(){
    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};

    // Table header
    cout << left << setw(12) << "StackSize"
         << setw(20) << "Avg Push (us)"
         << setw(20) << "Avg Pop (us)"
         << setw(20) << "Avg Add0 (us)"
         << setw(20) << "Avg Remove0 (us)" << endl;
    cout << string(92, '-') << endl;

    for (int n : sizes) {
        double avgPush, avgPop, avgAdd, avgRemove;

        // --- Benchmark push ---
        {
            ArrayStack<int> stack;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) stack.push(i);
            auto end = high_resolution_clock::now();
            avgPush = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark pop ---
        {
            ArrayStack<int> stack;
            for (int i = 0; i < n; i++) stack.push(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) stack.pop();
            auto end = high_resolution_clock::now();
            avgPop = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark add at index 0 (worst-case) ---
        {
            ArrayStack<int> stack;
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) stack.add(0, i);
            auto end = high_resolution_clock::now();
            avgAdd = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark remove from index 0 (worst-case) ---
        {
            ArrayStack<int> stack;
            for (int i = 0; i < n; i++) stack.push(i); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++) stack.remove(0);
            auto end = high_resolution_clock::now();
            avgRemove = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // Print results
        cout << left << setw(12) << n
             << setw(20) << fixed << setprecision(3) << avgPush
             << setw(20) << fixed << setprecision(3) << avgPop
             << setw(20) << fixed << setprecision(3) << avgAdd
             << setw(20) << fixed << setprecision(3) << avgRemove
             << endl;
    }



    return 0;
}