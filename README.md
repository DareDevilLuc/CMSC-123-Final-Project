# CMSC-123-Final-Project

## Project Description

This project is a comprehensive C++ implementation of various data structures, including arrays, deques, heaps, linked lists, priority queues, stacks, and more. It provides efficient implementations with benchmarking capabilities to compare performance across different data structures and operations.

The project is designed to be educational and practical, offering out-of-the-box implementations that are ready to use in C++ applications. It includes both header files for interfaces and source files for implementations, along with test suites that demonstrate usage and performance metrics.

### Key Features
- **Data Structures Implemented**:
  - Arrays
  - Deques (Array-based and Linked-list based)
  - Heaps (Meldable Heap)
  - Linked Lists (Singly and Doubly Linked)
  - Priority Queues
  - Queues
  - Stacks (Array-based and Linked-list based)
  - Sets (Sorted and Unsorted)
  - Hash Tables (Chained)
  - Red-Black Trees
  - Skip Lists
  - Adjacency Matrix for Graphs

- **Performance Benchmarking**: Comprehensive benchmarks for operations like insert, delete, push, pop, etc., across different data structure sizes.
- **Modular Design**: Clean separation between interfaces (include/) and implementations (src/).
- **Test Suites**: Executable test files that run benchmarks and output performance data.

### Goals
This project aims to:
- Provide efficient C++ implementations of fundamental data structures.
- Demonstrate performance characteristics of different data structures.
- Serve as a reference for data structure implementations and benchmarking.
- Support educational purposes in computer science courses.

### Key Concepts
- **Data Structure Efficiency**: Understanding time and space complexity trade-offs.
- **Benchmarking**: Measuring real-world performance of algorithms.
- **C++ Best Practices**: Memory management, templates, and object-oriented design.

### Development Status
This is a completed final project for CMSC-123. It includes full implementations and working benchmarks.

## Core Technical Concepts/Inspiration

This project exists to bridge the gap between theoretical data structure knowledge and practical implementation in C++. It provides concrete examples of how abstract concepts translate to code, with measurable performance implications.

Compared to standard library implementations (like STL), this project offers:
- Custom implementations for educational insight
- Detailed benchmarking data
- Focus on specific data structures not always covered in standard libraries

The project demonstrates key technical concepts such as:
- Dynamic memory allocation and deallocation
- Template metaprogramming for generic data structures
- Algorithm analysis and complexity theory in practice

## Getting Started

### Prerequisites
- C++ compiler (g++ recommended)
- Windows/Linux/macOS environment
- Basic knowledge of C++ and command-line tools

### Installation
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd CMSC-123-Final-Project
   ```

2. No additional dependencies required - pure C++ implementation.

### Configuration
No configuration needed. The project uses standard C++ features.

### Running the Project
The project consists of header files and test executables. Include the appropriate headers in your C++ projects and compile with g++.

## Tests

The project includes comprehensive benchmark tests for various data structures. Each test measures performance metrics for different operations and data sizes.

### Running Tests
To run a specific test:

1. Navigate to the project root directory
2. Compile the test file:
   ```bash
   g++ -O2 -o benchmark .\tests\NAME_OF_THE_FILE
   ```
   Replace `NAME_OF_THE_FILE` with the desired test file (e.g., `arraydeque.cpp`, `meldableheap.cpp`, etc.)

3. Run the benchmark:
   ```bash
   .\benchmark.exe
   ```

### Available Test Files
- `adjacencymatrix.cpp` - Graph adjacency matrix tests
- `arraydeque.cpp` - Array-based deque tests
- `arraystack.cpp` - Array-based stack tests
- `chainedhashtable.cpp` - Hash table tests
- `dllist.cpp` - Doubly linked list tests
- `meldableheap.cpp` - Meldable heap tests
- `redblacktrees.cpp` - Red-black tree tests
- `skiplist.cpp` - Skip list tests
- `sllist.cpp` - Singly linked list tests

### Benchmark Results

#### Deque Performance
```
DequeSize Avg addFirst (us) Avg addLast (us)  Avg removeFirst (us) Avg removeLast (us)
----------------------------------------------------------------------------------
1000      0.023             0.010             0.013                0.008
5000      0.012             0.008             0.009                0.006
10000     0.010             0.011             0.011                0.008
50000     0.013             0.013             0.014                0.012
100000    0.013             0.013             0.013                0.010
```

#### Heap Performance
```
HeapSize  log2(N)     Avg Insert (us)   Avg Delete (us)
----------------------------------------------------------
1000      9.97        0.149             0.206
5000      12.29       0.199             0.314
10000     13.29       0.218             0.334
50000     15.61       0.238             0.442
100000    16.61       0.248             0.492
```

#### List Performance
```
ListSize  Avg Push (us)     Avg Add (us)      Avg Pop (us)
----------------------------------------------------------------
1000      0.062             0.031             0.015
5000      0.042             0.036             0.017
10000     0.042             0.036             0.018
50000     0.040             0.039             0.018
100000    0.041             0.043             0.022
```

## Contributing

### Contributor Guidelines
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

### Code Style Requirements
- Follow C++ best practices
- Use consistent naming conventions (camelCase for variables, PascalCase for classes)
- Include comments for complex algorithms
- Ensure code compiles with g++ -O2

### Commit Message Format
- Use clear, descriptive commit messages
- Start with a verb (Add, Fix, Update, etc.)
- Keep messages under 50 characters when possible

## TODO

### Next Steps
- Add more data structure implementations


### Features Planned
- None as of yet

### Known Bugs
- None currently identified

## Contact

For questions or feedback about this project, please contact the project maintainer.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

```
MIT License

Copyright (c) 2024 CMSC-123-Final-Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
