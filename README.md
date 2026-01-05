# Language Bench - C++ vs Rust Performance Benchmarking

## Overview

This project presents a systematic performance comparison between **C++** and **Rust** across a set of core benchmarks commonly used to evaluate system-level programming languages. The objective of the project is to analyze execution performance, scalability, and runtime behavior under different workloads using a consistent and reproducible benchmarking methodology.

The benchmarks cover CPU-bound workloads, branch-heavy execution, recursion overhead, file I/O, string processing, and dynamic memory operations. All benchmarks were implemented separately in both C++ and Rust using equivalent logic and were executed under identical conditions to ensure fairness.

Each benchmark was executed multiple times, and **average execution time** along with **standard deviation** was recorded to capture both performance and run-to-run stability.

---

## Benchmarks Implemented

The following benchmarks were implemented in both C++ and Rust in the order listed below, progressing from CPU-bound workloads to I/O- and memory-intensive operations:

### 1. Summation Loop
A simple CPU-bound loop performing integer summation for a fixed number of iterations. This benchmark evaluates raw loop execution speed and compiler optimization efficiency.

### 2. Branch-Heavy Loop
A loop containing frequent conditional branches to analyze branch prediction behavior and control-flow performance under branch-heavy workloads.

### 3. Recursion Benchmark
A recursive function executed with controlled depth to measure function call overhead, stack usage, and recursion handling efficiency.

### 4. File Read Benchmark
Measures sequential file read performance by reading large files from disk, evaluating read throughput and file I/O efficiency.

### 5. File Write Benchmark
Measures sequential file write performance by writing large data blocks to disk, evaluating write throughput and runtime I/O overhead.

### 6. String Parsing and Concatenation Benchmark
Evaluates performance of string parsing and concatenation operations, representative of real-world text processing workloads.

### 7. Vector Insertion and Deletion
Measures dynamic memory and container performance by repeatedly inserting and deleting elements from a vector-like data structure. Large workloads are executed using chunked processing to respect physical memory limits while preserving the total operation count.

---

## Methodology

To ensure a fair and reliable comparison between C++ and Rust, the following benchmarking methodology was followed:

- Identical algorithms and workloads were used in both language implementations.
- All benchmarks were compiled in optimized (release) mode.
- Each benchmark was executed multiple times (typically five runs).
- Average execution time and standard deviation were calculated for each benchmark.
- No background applications were intentionally running during benchmark execution.
- All benchmarks were executed on the same machine, operating system, and compiler environment.

### Large Workloads and Chunking

For very large workloads (e.g., 500 million or 1 billion operations), allocating all data at once is not feasible due to physical memory constraints. In such cases, workloads were executed in **fixed-size chunks** while preserving the total number of operations. This approach maintains algorithmic equivalence while enabling scalable and realistic benchmarking.

---

## System Configuration

All benchmarks were executed on the following system:

### Hardware
- **Processor:** 12th Gen Intel® Core™ i5-1235U @ 1.30 GHz  
- **Installed RAM:** 8 GB (7.7 GB usable)  
- **Architecture:** 64-bit, x64-based processor  

### Operating System
- **OS:** Windows 11 Home Single Language  
- **Version:** 24H2  
- **OS Build:** 26100.7462  

---

## Toolchain and Build Configuration

- **C++ Compiler:** g++ (compiled with `-O3`)
- **Rust Compiler:** rustc (compiled using `rustc -O <filename.rs>`)
- **Timing Mechanisms:**
  - C++: `std::chrono`
  - Rust: `std::time::Instant`

Exact compiler versions and build commands are documented within the repository.

---

## Results

All benchmark results, including individual runs, average execution times, and standard deviation values, are documented in the Google Sheets link below:

📊 **Benchmark Results (Google Sheets)**  
https://docs.google.com/spreadsheets/d/1dq5R_SiZNLLnG3HRv5nI7fb26BDp2h8v44QNyywQqNw/edit?usp=sharing

A summary table consolidating results across all benchmarks and workloads was created to facilitate comparison and visualization.

---

## Visualization and Website

Benchmark results have been visualized using comparative charts (C++ vs Rust) for each benchmark and workload size. These visualizations, along with methodology and observations, are presented on a static website hosted using **GitHub Pages**.

🌐 **Benchmarking Website**  
[Link to website – to be added]

---

## Observations

- C++ and Rust demonstrate comparable performance across most benchmarks.
- Performance differences are generally small and often fall within the observed standard deviation.
- Both languages scale linearly with increasing workload sizes for CPU-bound benchmarks.
- I/O- and memory-heavy benchmarks highlight differences in runtime behavior and optimization strategies.

Detailed observations for each benchmark are available in the summary tables and visualizations.

---

## Limitations

- Benchmarks were executed on a single machine and operating system.
- Results may vary across different hardware, OS configurations, or compiler versions.
- Multithreaded and memory-pressure scenarios were not part of the initial benchmarking phase.

---

## Future Enhancements

Planned and potential future enhancements include:

- Benchmarking under different run conditions (e.g., memory pressure).
- Introducing multithreaded benchmarks with varying thread counts.
- Adding additional language comparisons (e.g., Go).
- Automating benchmark execution and result collection.

---

## Repository Structure

language-bench/
├── cpp/ # C++ benchmark implementations
├── rust/ # Rust benchmark implementations
├── data/ # Raw and processed benchmark results
├── charts/ # Generated charts and visuals
├── website/ # GitHub Pages website source
└── README.md

---

## Conclusion

This project provides a structured and reproducible comparison of C++ and Rust across a variety of fundamental performance benchmarks. By combining careful methodology, repeated measurements, and clear visualization, the project aims to offer practical insights into the real-world performance characteristics of modern systems programming languages.


## Repository Structure

