#include <fstream>
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main() {
    const long long SIZE = 100 * 1024 * 1024; // change size here
    ofstream file("write_test.bin", ios::binary);

    char buffer[4096] = {0};
    long long written = 0;

    auto start = high_resolution_clock::now();

    while (written < SIZE) {
        file.write(buffer, sizeof(buffer));
        written += sizeof(buffer);
    }

    file.flush(); // ensure data is written

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ File Write Time: " << elapsed.count() << " seconds\n";
    file.close();
    return 0;
}
