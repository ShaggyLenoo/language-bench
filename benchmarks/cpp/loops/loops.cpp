#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    const long long N = 1000000000;
    volatile long long sum = 0; // prevents loop over-optimization

    auto start = high_resolution_clock::now();

    for (long long i = 1; i <= N; i++) {
        sum += i;
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ Loop Time: " << elapsed.count() << " seconds\n";
    return 0;
}

