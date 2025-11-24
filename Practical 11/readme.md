# Stack vs Recursion Implementation

## Overview
This C++ program demonstrates two fundamental computer science concepts - recursion and stack-based iteration - by implementing Tower of Hanoi and Factorial operations using both approaches. The program provides a comparative analysis of how function calls are managed internally.

## Features

### 1. Dual Implementation Approach
- **Recursive Method**: Traditional function calling itself
- **Stack-based Method**: Manual stack simulation using array-based stack

### 2. Supported Operations
- **Tower of Hanoi**: Classic puzzle with disk movement simulation
- **Factorial Calculation**: Mathematical factorial computation

### 3. Custom Stack Implementation
- Array-based stack data structure
- Full stack operations (push, pop, peek, isEmpty, size)
- Memory management with constructor and destructor

## Algorithm Details

### Tower of Hanoi

#### Recursive Approach
```cpp
void hanoiRecursive(int n, char from, char to, char aux)
```
- **Base Case**: Move single disk directly
- **Recursive Steps**:
  1. Move n-1 disks from source to auxiliary
  2. Move nth disk from source to destination
  3. Move n-1 disks from auxiliary to destination

#### Stack-based Approach
```cpp
void hanoiStack(int n, char from, char to, char aux)
```
- **State Representation**: Uses stack to store (n, from, to, aux, stage)
- **Stage Management**:
  - Stage 0: First recursive call simulation
  - Stage 1: Disk movement and second recursive call
- **Manual Stack Management**: Explicit push/pop operations

### Factorial Calculation

#### Recursive Approach
```cpp
int factorialRecursive(int n)
```
- **Base Case**: n = 0 or 1 returns 1
- **Recursive Step**: n * factorial(n-1)

#### Stack-based Approach
```cpp
int factorialStack(int n)
```
- **Iterative Stack Use**: Push all numbers from n down to 2
- **Result Calculation**: Pop and multiply sequentially

## Code Structure

### Stack Class
```cpp
class Stack {
private:
    int* arr;       // Array to store stack elements
    int top;        // Top index
    int capacity;   // Maximum size
    
public:
    Stack(int size);    // Constructor
    ~Stack();           // Destructor
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};
```

### Key Functions

1. **`hanoiRecursive()`**: Classic recursive Tower of Hanoi
2. **`hanoiStack()`**: Stack-based iterative Tower of Hanoi
3. **`factorialRecursive()`**: Recursive factorial
4. **`factorialStack()`**: Stack-based factorial

## Menu System

### Level 1: Method Selection
```
Choose method:
1. Recursion
2. Stack
```

### Level 2: Operation Selection
```
Choose operation:
1. Tower of Hanoi
2. Factorial
```

## Usage Examples

### Example 1: Tower of Hanoi with Recursion
```
Choose method: 1
Choose operation: 1
Enter number of disks: 3

Output:
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

### Example 2: Factorial with Stack
```
Choose method: 2
Choose operation: 2
Enter number: 5

Output:
Factorial: 120
```

## Technical Comparison

### Recursion vs Stack Simulation

| Aspect | Recursion | Stack Simulation |
|--------|-----------|------------------|
| **Memory Usage** | Implicit call stack | Explicit stack object |
| **Code Readability** | High (clean, mathematical) | Lower (manual state management) |
| **Control** | Automatic | Manual |
| **Debugging** | Harder (implicit states) | Easier (explicit states) |
| **Stack Overflow Risk** | Higher for deep recursion | Controlled (fixed capacity) |

### Space Complexity
- **Recursive Hanoi**: O(n) call stack depth
- **Stack-based Hanoi**: O(n) explicit stack size
- **Both approaches** have similar space requirements but different management

### Time Complexity
- **Tower of Hanoi**: O(2ⁿ) for both approaches
- **Factorial**: O(n) for both approaches

## Educational Value

### Concepts Demonstrated
1. **Recursion Mechanics**: How function calls create stack frames
2. **Stack Data Structure**: Array-based implementation and operations
3. **State Management**: Manual simulation of recursion using stacks
4. **Algorithm Equivalence**: Different implementations solving same problems
5. **Memory Management**: Dynamic allocation and cleanup

### Learning Outcomes
- Understand how recursion works internally
- Learn to simulate recursion using iterative methods
- Gain insight into compiler's stack management
- Develop skills in state machine design
- Compare trade-offs between different implementation approaches

## Compilation and Execution

### Requirements
- C++ compiler
- Standard library support

### Compilation Command
```bash
g++ -o stack_recursion program.cpp
./stack_recursion
```

## Applications

### Real-world Use Cases
1. **Compiler Design**: Understanding function call mechanisms
2. **Algorithm Education**: Teaching recursion concepts
3. **Memory-limited Systems**: Stack-based alternatives to deep recursion
4. **Debugging Tools**: Stack trace analysis and simulation

### Advanced Extensions
- Add performance timing comparison
- Implement stack depth monitoring
- Add visualization for stack states
- Extend to other recursive problems (Fibonacci, tree traversals)

## Error Handling
- **Stack Overflow**: Prevents pushing when stack is full
- **Stack Underflow**: Prevents popping from empty stack
- **Input Validation**: Basic user input handling
