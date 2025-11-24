# Polynomial Operations using Linked Lists

## Project Description
A C++ implementation of polynomial operations using Singly Linked Lists and Generalized Linked Lists (GLL) for efficient representation and manipulation of polynomials, with special focus on sparse polynomial handling.

## Features
- Polynomial representation using Singly Linked Lists
- Generalized Linked List (GLL) for sparse polynomials
- Polynomial addition operation
- Dynamic memory management
- Sparse polynomial efficient storage

## Data Structures

### Node Structure (Singly Linked List)
```cpp
struct Node {
    int coeff;    // Coefficient
    int exp;      // Exponent
    Node* next;   // Pointer to next term
};
```

### GLLNode Structure (Generalized Linked List)
```cpp
struct GLLNode {
    int flag;     // 0 for data, 1 for down pointer
    union {
        struct {
            int coeff;
            int exp;
        } data;
        Node* down;
    } u;
    GLLNode* next;
};
```

## Functions Implemented

### Core Operations
- `insertNode()` - Insert term into polynomial
- `insertGLLNode()` - Insert node into GLL
- `printPolynomial()` - Display polynomial
- `printGLLPolynomial()` - Display GLL polynomial
- `addPolynomials()` - Add two polynomials
- `createSparsePolynomial()` - Create sparse polynomial using GLL

### Memory Management
- `freePolynomial()` - Free linked list memory
- `freeGLL()` - Free GLL memory

## Usage

### Regular Polynomial Operations
```cpp
Node* poly1 = nullptr;
insertNode(poly1, 5, 3);  // 5x^3
insertNode(poly1, 4, 2);  // 4x^2
insertNode(poly1, 2, 0);  // 2

Node* result = addPolynomials(poly1, poly2);
```

### Sparse Polynomial using GLL
```cpp
int sparseTerms[][2] = {{7, 100}, {3, 50}, {2, 10}};
GLLNode* sparsePoly = createSparsePolynomial(sparseTerms, 3);
```

## Advantages

### Singly Linked List Approach
- Dynamic memory allocation
- Efficient insertion and deletion
- No memory wastage for sparse data
- Flexible size management

### GLL for Sparse Polynomials
- Optimal storage for large exponents
- Memory efficient for few non-zero terms
- Hierarchical representation capability
- Better performance for sparse data

## Time Complexity
- **Insertion**: O(n)
- **Addition**: O(m + n)
- **Traversal**: O(n)

## Space Complexity
- **Storage**: O(n) for n terms
- **Auxiliary**: O(m + n) for addition

## Applications
- Computer algebra systems
- Mathematical computations
- Signal processing
- Scientific computing
- Educational tools

## Compilation
g++ -o polynomial_main polynomial_code.cpp
./polynomial_main


## Example Output
First Polynomial: 5x^3 + 4x^2 + 2
Second Polynomial: 3x^3 + 2x + 1
Result: 8x^3 + 4x^2 + 2x + 3

Sparse Polynomial: 7x^100 + 3x^50 + 2x^10


## Memory Management
All dynamically allocated memory is properly freed using dedicated cleanup functions to prevent memory leaks.

## Contributing
Feel free to extend this implementation with additional polynomial operations like multiplication, differentiation, or evaluation.