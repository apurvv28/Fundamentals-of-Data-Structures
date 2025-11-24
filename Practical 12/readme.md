# Queue Management System

## Overview
A comprehensive C++ implementation of various queue data structures with real-world applications. This menu-driven program demonstrates different types of queues and their practical uses in systems like printer spooling, traffic management, and emergency services.

## Features

### Supported Queue Types
1. **Linear Queue** - Basic FIFO structure (Printer Spooling)
2. **Circular Queue** - Efficient memory utilization (Traffic Management)
3. **Deque** - Double-ended queue with input/output restrictions
4. **Priority Queue** - Ascending/Descending priority (Emergency Services)
5. **Linked Queue** - Dynamic memory allocation

## Real-World Applications

### Linear Queue - Printer Spooling
- **Use Case**: Print job management in office environments
- **Characteristics**: Simple FIFO, fixed size, sequential processing
- **Limitations**: Memory wastage after dequeuing

### Circular Queue - Traffic Management
- **Use Case**: Traffic light sequencing, vehicle flow control
- **Characteristics**: Efficient memory reuse, circular buffer
- **Advantages**: No memory wastage, continuous operation

### Deque - Input/Restricted Operations
- **Use Case**: Undo-redo operations, browser history
- **Characteristics**: Insert/delete from both ends
- **Variants**: Input-restricted & Output-restricted

### Priority Queue - Emergency Services
- **Use Case**: Hospital triage, emergency response systems
- **Characteristics**: Elements processed based on priority
- **Types**: Ascending (min-heap) & Descending (max-heap)

### Linked Queue - Dynamic Memory
- **Use Case**: Dynamic data streaming, unpredictable workloads
- **Characteristics**: No size limitation, dynamic memory allocation
- **Advantages**: Flexible size, efficient memory usage

## Menu Structure

### Main Menu (Level 1)
```
=== QUEUE MANAGEMENT SYSTEM ===
1. Linear Queue (Printer Spooling)
2. Circular Queue (Traffic Management)
3. Deque (Input/Restricted Operations)
4. Priority Queue (Emergency Services)
5. Linked Queue (Dynamic Memory)
6. Exit
```

### Operations Menu (Level 2)

#### For Linear, Circular & Linked Queues:
```
1. Enqueue/Insert
2. Dequeue/Delete
3. Display Queue
4. Back to Main Menu
```

#### For Deque:
```
1. Insert at Rear
2. Delete from Front
3. Display Queue
4. Insert at Front
5. Insert at Rear
6. Delete from Front
7. Delete from Rear
8. Back to Main Menu
```

#### For Priority Queue:
```
1. Enqueue/Insert
2. Dequeue/Delete
3. Display Queue
4. Use Ascending Priority
5. Use Descending Priority
6. Back to Main Menu
```

## Technical Implementation

### Class Structure

#### 1. LinearQueue
- **Data Structure**: Array-based
- **Operations**: enqueue(), dequeue(), isFull(), isEmpty()
- **Pointers**: front, rear

#### 2. CircularQueue
- **Data Structure**: Circular array
- **Operations**: Circular enqueue/dequeue with modulo arithmetic
- **Advantage**: Prevents memory wastage

#### 3. Deque
- **Data Structure**: Circular array with double-ended operations
- **Operations**: insertFront(), insertRear(), deleteFront(), deleteRear()
- **Flexibility**: Bidirectional operations

#### 4. PriorityQueue
- **Data Structure**: Sorted array
- **Operations**: Priority-based insertion
- **Modes**: Ascending & Descending priority

#### 5. LinkedQueue
- **Data Structure**: Singly linked list
- **Operations**: Dynamic memory allocation
- **Advantage**: No fixed size limitation

## Code Features

### Error Handling
- Stack overflow/underflow detection
- Empty queue checks
- Full queue validations
- Invalid input handling

### Memory Management
- Dynamic allocation for LinkedQueue
- Automatic cleanup using destructors
- Efficient memory usage in CircularQueue

### User Interface
- Intuitive menu navigation
- Clear operation feedback
- Real-time queue visualization
- Contextual operation menus

## Compilation and Execution

### Requirements
- C++ compiler (g++, clang++, etc.)
- Standard Template Library support

### Compilation
```bash
g++ -o queue_system queue_implementation.cpp
./queue_system
```

## Usage Examples

### Example 1: Printer Spooling (Linear Queue)
```
Choose: 1 (Linear Queue)
Operations:
1. Enqueue - Add print jobs
2. Dequeue - Process print jobs
3. Display - Show pending jobs
```

### Example 2: Traffic Management (Circular Queue)
```
Choose: 2 (Circular Queue)
Operations:
1. Enqueue - Add vehicles to lane
2. Dequeue - Process vehicles
3. Display - Show traffic flow
```

### Example 3: Emergency Triage (Priority Queue)
```
Choose: 4 (Priority Queue)
Operations:
4. Ascending - Lower numbers = higher priority
5. Descending - Higher numbers = higher priority
```

## Educational Value

### Concepts Demonstrated
1. **FIFO Principle** - Fundamental queue behavior
2. **Memory Management** - Array vs Linked list implementations
3. **Algorithm Efficiency** - Time and space complexity
4. **Real-world Applications** - Practical use cases
5. **Data Structure Design** - Class architecture and encapsulation

### Learning Outcomes
- Understand different queue variations and their trade-offs
- Learn when to use specific queue types for different scenarios
- Implement complex data structures with proper error handling
- Develop menu-driven applications with nested control structures
- Apply object-oriented programming principles to data structures

## Applications in Software Systems

### Operating Systems
- Process scheduling
- I/O buffer management
- Inter-process communication

### Network Systems
- Packet routing
- Message queues
- Bandwidth management

### Real-time Systems
- Task scheduling
- Event handling
- Resource allocation

### Database Systems
- Transaction processing
- Query optimization
- Connection pooling

## Extension Possibilities

### Additional Features
- Thread-safe implementations
- Persistence to file/database
- Graphical visualization
- Performance metrics
- Multi-threaded processing

### Advanced Queue Types
- Blocking Queue
- Delay Queue
- Synchronous Queue
- Transfer Queue
