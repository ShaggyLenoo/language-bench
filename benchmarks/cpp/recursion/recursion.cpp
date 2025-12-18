#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long fib(long long n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    const int N = 40;

    auto start = high_resolution_clock::now();

    volatile long long result = fib(N);

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ Recursion Time: " << elapsed.count() << " seconds\n";
    return 0;
}
