#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    const int REPEAT = 100000; // change this to scale workload
    string pattern =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        "abcd"; // total length = 100 chars

    string text;
    text.reserve(pattern.size() * REPEAT);

    for (int i = 0; i < REPEAT; i++) {
        text += pattern;
    }

    volatile long long count = 0;

    auto start = high_resolution_clock::now();

    for (char c : text) {
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')) {
            count++;
        }
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ String Parse Time: "
         << elapsed.count() << " seconds\n";

    return 0;
}
