# Sparse Matrix Operations in C++

This repository contains **two C++ programs** demonstrating sparse matrix operations:

1. **Fast Transpose of a Sparse Matrix**
2. **Addition of Two Sparse Matrices**

Both programs use the **triplet representation** `(row, column, value)` for sparse matrices to optimize storage and computation.

---

## 1. Fast Transpose of a Sparse Matrix

### Description

This program converts a standard 2D matrix into a sparse representation and computes its transpose efficiently using two methods:

1. **Simple Transpose** – Scans columns one by one and swaps row and column indices.
2. **Fast Transpose** – Uses a precomputed `count` array to directly place each element in its correct position for the transpose.

### How it Works

- Input a 2D matrix from the user.
- Convert it to a sparse matrix by storing only non-zero elements in a `Triple` array.
- Compute both the **simple** and **fast transpose** and display them.

### Usage

>> Enter the number of rows, columns, and matrix elements when prompted.

### 2. Addition of Two Sparse Matrices
1. This program performs addition of two matrices using their sparse representation:
2. Converts both matrices into Triple arrays storing only non-zero elements.
3. Merges the arrays intelligently: if positions match, values are added; otherwise, elements are appended.
4. Prints the resultant sparse matrix.

### How it Works
1. dimensions and elements of both matrices.
2. Convert to sparse representation.
3. Add matrices efficiently using position matching.
4. Display the resulting sparse matrix in triplet form.

### Usage
1. Enter matrix dimensions and elements as prompted.

>> Sparse Matrix Representation
1. Triplet format: Each non-zero element is stored as (row, column, value).
2. Reduces memory usage when matrices have a large number of zeros.
3. Efficient for operations like transpose and addition because computation only involves non-zero elements.

## Time and Space Efficiency Analysis
Operation	            Naive 2D Matrix	     Sparse Representation (Triplet)
Storage	                O(rows*cols)	     O(nz) (number of non-zero elements)
Transpose (simple)	    O(rows*cols)	     O(nz*cols)
Transpose (fast)	    O(rows*cols)	     O(nz + cols)
Addition	            O(rows*cols)	     O(nz1 + nz2)
Memory Access Pattern	Dense array access	 Only non-zero elements accessed

## Analysis:

1. Space efficiency: Sparse matrices drastically reduce memory consumption for matrices with many zeros.

2. Time efficiency: Operations like addition and fast transpose operate only on non-zero elements, improving runtime for large, sparse datasets.

3. Real-world relevance: Sparse matrix operations are essential in:
    a. Handling large-scale data fragmentation in distributed systems.
    b. Graph algorithms, recommendation systems, and scientific computing where datasets are mostly empty.
    c. Reducing network and memory overhead in distributed storage of large sparse datasets.
    d. Fast Transpose vs Simple Transpose:
    e. Simple transpose iterates through each column for each element, which is O(nz*cols) in worst-case scenarios.
    f. Fast transpose uses a count and index array to place elements directly, reducing overhead to O(nz + cols).


## Author
- Apurv Saktepar
