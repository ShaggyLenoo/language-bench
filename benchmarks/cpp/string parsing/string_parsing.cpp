#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    const int REPEAT = 1'000'0000; // 100 MB
    string pattern =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        "abcd"; // 100 chars

    string text;
    text.reserve(pattern.size() * REPEAT);

    for (int i = 0; i < REPEAT; i++) {
        text += pattern;
    }

    volatile unsigned long long count = 0; // dependency blocks vectorization

    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < text.size(); i++) {
        unsigned char c = text[i];
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')) {
            count += 1;
        }
    }

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ String Parse Time: "
         << elapsed.count() << " seconds\n";
    cout << "Count: " << count << "\n";

    return 0;
}
