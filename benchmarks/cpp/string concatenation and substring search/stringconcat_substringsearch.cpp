#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    const int REPEAT = 1'000'0000; // Scale workload

    string chunk =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        "abcd"; // 100 chars

    string text;
    text.reserve(chunk.size() * REPEAT);

    string needle = "XYZ123";

    auto start = high_resolution_clock::now();

    // ---- String Concatenation ----
    for (int i = 0; i < REPEAT; i++) {
        text += chunk;
    }

    // ---- Substring Search ----
    size_t pos = text.find(needle);

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ Concat + Search Time: "
         << elapsed.count() << " seconds\n";

    // Prevent over optimization
    cout << "Found at: " << pos << "\n";

    return 0;
}
