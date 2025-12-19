#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    const char* filename = "testfile.txt";
    volatile size_t bytes_read = 0;

    auto start = high_resolution_clock::now();

    ifstream file(filename, ios::binary);
    char buffer[4096];

    while (file.read(buffer, sizeof(buffer))) {
        bytes_read += file.gcount();
    }
    bytes_read += file.gcount(); // last partial read

    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;

    cout << "C++ File Read Time: " << elapsed.count() << " seconds\n";
    return 0;
}
