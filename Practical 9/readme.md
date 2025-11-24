# Linked List Playlist Management System

## Overview
This project contains two C++ implementations of music playlist management systems using different linked list data structures. The programs demonstrate how various linked list types can be used to efficiently manage dynamic data in real-world applications like music players.

## Code 1: Multi-Linked List Playlist Manager

### Description
A comprehensive playlist management system that implements three different types of linked lists:
- **Singly Linked List**
- **Doubly Linked List** 
- **Circular Linked List**

### Features
- **Add Song**: Insert new songs into the playlist
- **Delete Song**: Remove songs by title
- **Search Song**: Find songs in the playlist
- **Update Song**: Modify song details
- **Display Playlist**: Show all songs in the playlist
- **Arrange Songs**: Sort songs alphabetically by title

### Data Structures Used
1. **Singly Linked List**: Linear collection with unidirectional navigation
2. **Doubly Linked List**: Bidirectional navigation with previous and next pointers
3. **Circular Linked List**: Last node points back to the first node

### Key Operations
- **Insertion**: Adds songs at the end of the list
- **Deletion**: Removes specific songs while maintaining list integrity
- **Traversal**: Navigates through the list to display or search
- **Sorting**: Implements bubble sort for alphabetical arrangement

### Menu Structure
```
Main Menu → List Type Selection → Operations Menu
```

## Code 2: Advanced Playlist Management System

### Description
A more complex implementation featuring hierarchical linked lists with playlist and song management using doubly linked lists.

### Features
- **Create Playlist**: Make new playlist containers
- **Display Playlists**: Show all available playlists
- **Add Songs**: Insert songs into specific playlists
- **Display Songs**: Show songs within a playlist
- **Search Song**: Find songs across all playlists
- **Sort Songs**: Alphabetically organize songs within playlists
- **Concatenate Playlists**: Merge songs from multiple playlists

### Data Structure Architecture
- **Outer Layer**: Doubly linked list of Playlist nodes
- **Inner Layer**: Doubly linked list of Song nodes within each playlist

### Advanced Operations
- **Hierarchical Management**: Nested linked lists for playlists and songs
- **Cross-Playlist Search**: Search songs across all playlists
- **Playlist Concatenation**: Merge multiple playlists
- **Bidirectional Navigation**: Efficient traversal in both directions

### Real-World Simulation
This implementation closely mimics actual music player software with:
- Separate playlist management
- Song organization within playlists
- Cross-platform search capabilities
- Playlist merging functionality

## Technical Comparison

| Aspect | Code 1 | Code 2 |
|--------|---------|---------|
| **List Types** | Singly, Doubly, Circular | Doubly Linked (Hierarchical) |
| **Structure** | Flat song lists | Nested playlists and songs |
| **Navigation** | Type-specific traversal | Bidirectional at both levels |
| **Use Case** | Educational comparison | Practical music player simulation |
| **Complexity** | Multiple independent lists | Hierarchical relationship |

## Learning Outcomes

### Code 1 Demonstrates:
- Differences between singly, doubly, and circular linked lists
- How pointer management varies between list types
- Memory efficiency comparisons
- Traversal limitations and advantages

### Code 2 Demonstrates:
- Real-world application of linked lists
- Hierarchical data management
- Complex operations like concatenation
- Practical software architecture patterns

## Compilation and Execution

### Requirements
- C++ compiler (g++, clang++, etc.)
- Standard Template Library support

### Compilation Command
```bash
g++ -o playlist_manager code1.cpp
./playlist_manager
```

## Educational Value
These implementations provide hands-on experience with:
- Pointer manipulation and memory management
- Different linked list variants and their trade-offs
- Algorithm implementation on linked structures
- Real-world data structure applications
- Menu-driven program design
- Error handling and user input validation
