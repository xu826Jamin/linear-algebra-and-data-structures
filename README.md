# linear-algebra-and-data-structures

## Overview
This project is a collection of C programs developed for Lab 2 of the McMaster Principles of Programming course. It solves several fundamental programming problems involving linear algebra operations, matrix traversal, efficient data representation for sparse vectors, and sorting algorithms for custom data structures. This project matters because it reinforces core concepts in C programming, such as array manipulation, pointer arithmetic, struct usage, and algorithm implementation.

## Features
- **Vector Operations (Question 1):** Implements vector addition, scalar product (dot product), and Euclidean norm calculation for double-precision vectors.
- **Matrix Diagonal Scan (Question 2):** Converts a fixed-size (3x3) matrix into a 1D array by scanning its elements diagonally.
- **Sparse Vector Compression (Question 3):** 
  - Converts a standard integer array into an efficient sparse vector representation using a custom struct (`Q3Struct`) to store only non-zero elements and their indices.
  - Reconstructs the original vector from the efficient representation.
  - Handles edge cases where the vector is full of zeros or fully populated.
- **Structure Sorting (Question 4):** 
  - Sorts an array of `Q4Struct` structures based on an integer field (`intData`).
  - Implements two sorting algorithms: Bubble Sort and Selection Sort.
  - Preserves the association between the integer key and the character data (`charData`) during the sort.

## Tech Stack
- **Language:** C (GCC compiler)
- **Build System:** GNU Make
- **Testing/Scripting:** Bash script (`run.sh`) for executing the compiled binary.
- **Libraries:** Standard C Library, Math Library (`libm`).

## Design Decisions
**Sparse Vector Representation (Question 3):**
One tradeoff made was using a struct `{int val; int pos;}` to represent non-zero elements. 
- **Why:** This significantly reduces memory usage for vectors that are mostly zeros (sparse), which is common in many scientific computing applications.
- **Tradeoff:** It increases the complexity of accessing the $i$-th element of the vector compared to a direct array index lookup, as you might need to search the struct array.

**Sorting Algorithms (Question 4):**
We implemented both Bubble Sort and Selection Sort.
- **Why:** To demonstrate and compare two fundamental $O(n^2)$ sorting algorithms. While not the most efficient for very large datasets (compared to QuickSort or MergeSort), they are simple to implement and sufficient for small arrays of structures.

## How to Run
1. **Compile the project:**
   Open a terminal in the project directory and run:
   ```bash
   make
   ```
   This will compile the source files and generate an executable named `Lab2`.

2. **Run the program/tests:**
   You can run the executable directly:
   ```bash
   ./Lab2
   ```
   Or use the provided test script via make:
   ```bash
   make test
   ```

3. **Clean up:**
   To remove object files and the executable:
   ```bash
   make clean
   ```

## What I Learned
- **Pointers and Arrays:** Deepened understanding of passing arrays to functions and using pointers for array manipulation.
- **Structs in C:** Learned how to define and use structures to group related data (like value-position pairs or int-char pairs).
- **Algorithm Implementation:** Gained practical experience implementing mathematical formulas (norms, dot products) and sorting logic (bubble/selection sort) from scratch.
- **Memory Efficiency:** Understood the concept of sparse data and how to optimize storage for specific data patterns.
- **Build Automation:** Learned to use `makefile` to manage compilation dependencies and build steps.
