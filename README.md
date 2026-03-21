# CMSC-123-Final-Project

## Project Description

This project is a comprehensive C++ implementation of various data structures, including arrays, deques, heaps, linked lists, priority queues, stacks, and more. It provides efficient implementations with benchmarking capabilities to compare performance across different data structures and operations.

The project is designed to be educational and practical, offering out-of-the-box implementations that are ready to use in C++ applications. It includes both header files for interfaces and source files for implementations, along with test suites that demonstrate usage and performance metrics.

### Key Features
- **Data Structures Implemented**:
  - Arrays
  - Deques (Array-based)
  - Heaps (Meldable Heap)
  - Linked Lists (Singly and Doubly Linked)
  - Priority Queues
  - Queue (Link-list based)
  - Stack (Array-based)
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
This is a completed final project for CMSC-123. It includes full implementations and working benchmarks. After passing this project for the course. This repository/project may be used to include more data structures outside the scope of the course. 

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
   Why `-O2`? This is an optimization flag that allows the code to run without the overheads that may skew with the time. It enables various optimizations like inlining small functions,   removing unnecessary code, and optimizing loops, which makes benchmarks and performance tests more realistic compared to unoptimized builds.

4. Run the benchmark:
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

#### SLList Performance
```
SLListSize  Avg Push (us)     Avg Add (us)      Avg Pop (us)      Avg Remove (us)   
----------------------------------------------------------------------------------
1000      0.093             0.034             0.017             0.307
5000      0.042             0.037             0.019             4.164
10000     0.057             0.037             0.020             9.685
50000     0.046             0.047             0.031             50.899
100000    0.040             0.047             0.030             105.135
```

#### Array Stack Performance
```
StackSize   Avg Push (us)       Avg Pop (us)        Avg Add0 (us)       Avg Remove0 (us)    
--------------------------------------------------------------------------------------------
1000        0.043               0.042               1.358               1.310
5000        0.018               0.025               6.844               6.302
10000       0.051               0.032               16.027              12.912
50000       0.015               0.053               71.537              100.128
100000      0.028               0.062               193.831             197.958
```

#### Queue (Linked-list based) Performance
```
QueueSize   Avg Push (us)       Avg Pop (us)        Avg Peek (us)       Mixed Ops (us)      
--------------------------------------------------------------------------------------------
1000        0.657               6.004               0.002               5.163
5000        1.887               27.111              0.001               20.231
10000       13.830              56.672              0.001               42.113
50000       11.627              106.755             0.003               54.293
100000      24.320              118.455             0.003               36.780
```

#### DLList Performance
```
ListSize    Avg AddEnd (us)     Avg RemoveEnd (us)  Avg Add0 (us)       Avg Remove0 (us)    
--------------------------------------------------------------------------------------------
1000        0.557               6.345               5.594               5.453
5000        1.590               31.522              30.189              31.022
10000       15.370              58.324              60.816              57.092
50000       13.389              71.944              54.225              72.067
100000      26.391              80.933              24.183              73.577
```

#### CHained Hash Table Performance
```
TableSize   Avg Insert (us)     Avg isPresent (us)  Avg Remove (us)
------------------------------------------------------------------------
1000        0.081               0.000               0.019
5000        0.047               0.000               0.024
10000       0.042               0.000               0.046
50000       0.045               0.000               0.035
100000      0.046               0.000               0.098
```
#### Graph Adjacency Matrix Performance
```
GraphSize   Avg add (us)        Avg remove (us)     Avg hasEdge (us)    Avg outEdges (us)   Avg inEdges (us)    
----------------------------------------------------------------------------------------------------------------
100         0.020               0.021               0.021               6.840               6.500               
500         0.019               0.017               0.018               7.822               7.950               
1000        0.030               0.029               0.029               7.592               11.203              
2000        0.014               0.014               0.014               8.172               7.499               
3000        0.010               0.009               0.008               6.860               11.752 
```
#### Redblack Trees Performance
```
TreeSize    Avg add (us)      Avg remove (us)   Avg hasElement (us)
------------------------------------------------------------------
1000        0.091             0.051             0.037             
5000        0.113             0.052             0.053             
10000       0.125             0.097             0.075             
50000      
 0.214             0.080             0.085             
100000      0.176             0.064             0.060        
```
### Skiplist Performance
```
ListSize    Avg add (us)      Avg remove (us)   Avg hasElement (us)
------------------------------------------------------------------
1000        1.841             1.496             0.389             
5000        1.983             1.293             0.408             
10000       1.455             0.571             0.221             
50000       0.707             0.510             0.206             
100000      0.689             0.503             0.212      
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
