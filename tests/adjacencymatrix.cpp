#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../src/adjacencymatrix.h"

using namespace std;
using namespace chrono;

int main() {
    vector<int> sizes = {100, 500, 1000, 2000, 3000};

    // Table header
    cout << left << setw(12) << "GraphSize"
         << setw(20) << "Avg add (us)"
         << setw(20) << "Avg remove (us)"
         << setw(20) << "Avg hasEdge (us)"
         << setw(20) << "Avg outEdges (us)"
         << setw(20) << "Avg inEdges (us)" << endl;
    cout << string(112, '-') << endl;

    for (int n : sizes) {
        double avgAdd, avgRemove, avgHasEdge, avgOutEdges, avgInEdges;

        // Number of edge operations: each vertex i connects to up to 9 neighbors
        long long ops = 0;
        for (int i = 0; i < n; i++)
            ops += min(9, n - i - 1);

        // --- Benchmark add ---
        {
            AdjacentMatrix g(n);
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.add(i, j);
            auto end = high_resolution_clock::now();
            avgAdd = ops > 0
                ? duration_cast<microseconds>(end - start).count() / double(ops)
                : 0.0;
        }

        // --- Benchmark remove ---
        {
            AdjacentMatrix g(n);
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.add(i, j); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.remove(i, j);
            auto end = high_resolution_clock::now();
            avgRemove = ops > 0
                ? duration_cast<microseconds>(end - start).count() / double(ops)
                : 0.0;
        }

        // --- Benchmark hasEdge ---
        {
            AdjacentMatrix g(n);
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.add(i, j); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.hasEdge(i, j);
            auto end = high_resolution_clock::now();
            avgHasEdge = ops > 0
                ? duration_cast<microseconds>(end - start).count() / double(ops)
                : 0.0;
        }

        // --- Benchmark outEdges ---
        {
            AdjacentMatrix g(n);
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.add(i, j); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++)
                g.outEdges(i);
            auto end = high_resolution_clock::now();
            avgOutEdges = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // --- Benchmark inEdges ---
        {
            AdjacentMatrix g(n);
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n && j < i + 10; j++)
                    g.add(i, j); // pre-fill
            auto start = high_resolution_clock::now();
            for (int i = 0; i < n; i++)
                g.inEdges(i);
            auto end = high_resolution_clock::now();
            avgInEdges = duration_cast<microseconds>(end - start).count() / double(n);
        }

        // Print results
        cout << left << setw(12) << n
             << setw(20) << fixed << setprecision(3) << avgAdd
             << setw(20) << fixed << setprecision(3) << avgRemove
             << setw(20) << fixed << setprecision(3) << avgHasEdge
             << setw(20) << fixed << setprecision(3) << avgOutEdges
             << setw(20) << fixed << setprecision(3) << avgInEdges
             << endl;
    }

    return 0;
}