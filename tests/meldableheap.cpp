#include <iostream>
#include <chrono>
#include <vector>
#include "../src/sllist.h"

// -----------------------------------------------

using Clock = std::chrono::high_resolution_clock;

double ms(std::chrono::nanoseconds ns) {
    return ns.count() / 1e6;
}

void print_result(const std::string& label, std::chrono::nanoseconds elapsed, int N) {
    std::cout << "  " << label
              << ": " << ms(elapsed) << " ms"
              << "  (" << N << " ops)\n";
}

int main() {
    const int N = 1'000'000;

    std::cout << "=== SLList Benchmark (N = " << N << ") ===\n\n";

    // --- push() benchmark ---
    {
        SLList<int> list;
        auto t0 = Clock::now();
        for (int i = 0; i < N; i++) list.push(i);
        auto t1 = Clock::now();
        print_result("push() x" + std::to_string(N), t1 - t0, N);
    }

    // --- add() benchmark ---
    {
        SLList<int> list;
        auto t0 = Clock::now();
        for (int i = 0; i < N; i++) list.add(i);
        auto t1 = Clock::now();
        print_result("add()  x" + std::to_string(N), t1 - t0, N);
    }

    // --- pop() benchmark (pre-fill, then time pops) ---
    {
        SLList<int> list;
        for (int i = 0; i < N; i++) list.push(i);

        auto t0 = Clock::now();
        for (int i = 0; i < N; i++) list.pop();
        auto t1 = Clock::now();
        print_result("pop()  x" + std::to_string(N), t1 - t0, N);
    }

    // --- mixed: alternating push + pop ---
    {
        SLList<int> list;
        auto t0 = Clock::now();
        for (int i = 0; i < N; i++) {
            list.push(i);
            if (i % 2 == 0) list.pop();
        }
        auto t1 = Clock::now();
        print_result("mixed push+pop  x" + std::to_string(N), t1 - t0, N);
    }

    std::cout << "\nDone.\n";
    return 0;
}