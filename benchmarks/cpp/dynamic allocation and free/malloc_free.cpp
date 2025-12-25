#include <iostream>
#include <chrono>
#include <cstdlib>

int main() {
    const size_t N = 1000000;

    volatile size_t counter = 0; // prevents extra optimization

    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < N; i++) {
        int* p = (int*)malloc(sizeof(int));
        counter += (p != nullptr);
        free(p);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t = end - start;

    std::cout << "C++ malloc/free time: " << t.count() << " s\n";
    std::cout << "Counter: " << counter << "\n";

    return 0;
}
