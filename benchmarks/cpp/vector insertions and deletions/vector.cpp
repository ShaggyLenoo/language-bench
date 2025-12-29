#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const size_t TOTAL = 10'000'000;   // scale this
    const size_t CHUNK = 10'000'000;      // 40 MB
    volatile long long sum = 0;

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t done = 0; done < TOTAL; done += CHUNK) {
        size_t n = (TOTAL - done < CHUNK) ? (TOTAL - done) : CHUNK;

        std::vector<int> v;
        v.reserve(n);

        for (size_t i = 0; i < n; i++)
            v.push_back(i);

        while (!v.empty()) {
            sum += v.back();
            v.pop_back();
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "C++ Vector time: "
              << std::chrono::duration<double>(end - start).count()
              << " s\n";
    std::cout << "Sum: " << sum << "\n";
}
