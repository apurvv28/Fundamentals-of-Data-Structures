# Gaming Leaderboard Sorting System

A comprehensive C++ implementation of various sorting algorithms optimized for gaming leaderboard management with performance tracking capabilities.

## 📋 Project Overview

This program demonstrates and compares multiple sorting algorithms specifically configured for sorting gaming scores in descending order (highest to lowest). The system tracks and displays key performance metrics including execution time, number of swaps, and comparisons for each algorithm.

## 🎯 Features

- **7 Sorting Algorithms** implemented for descending order
- **Real-time Performance Metrics** tracking
- **Interactive Menu System** for algorithm selection
- **Score Management** for gaming leaderboards
- **Comprehensive Analysis** of algorithm efficiency

## 🚀 Algorithms Implemented

### 1. Bubble Sort
- **Type**: Comparison-based
- **Approach**: Repeatedly compares and swaps adjacent elements
- **Best for**: Educational purposes, small datasets
- **Performance**: O(n²) time complexity

### 2. Insertion Sort
- **Type**: Comparison-based, Stable
- **Approach**: Builds sorted array one element at a time
- **Best for**: Small or nearly sorted datasets
- **Performance**: O(n²) time complexity

### 3. Selection Sort
- **Type**: Comparison-based
- **Approach**: Repeatedly finds maximum element and swaps
- **Best for**: Small datasets with limited memory
- **Performance**: O(n²) time complexity

### 4. Quick Sort
- **Type**: Comparison-based, Divide & Conquer
- **Approach**: Partitions array around pivot element
- **Best for**: General purpose, large datasets
- **Performance**: O(n log n) average case

### 5. Shell Sort
- **Type**: Comparison-based
- **Approach**: Generalized insertion sort with gap sequence
- **Best for**: Medium-sized datasets
- **Performance**: O(n log n) to O(n²)

### 6. Bucket Sort
- **Type**: Non-comparison-based, Stable
- **Approach**: Distributes elements into buckets
- **Best for**: Uniformly distributed integer scores
- **Performance**: O(n + k) where k is bucket range

### 7. Radix Sort
- **Type**: Non-comparison-based
- **Approach**: Sorts by individual digits using counting sort
- **Best for**: Integer scores with limited digit range
- **Performance**: O(d(n + k)) where d is digit count

## 📊 Performance Metrics Tracked

- **Execution Time**: Measured in microseconds
- **Swap Count**: Number of element exchanges
- **Comparison Count**: Number of element comparisons

## 🛠️ Installation & Compilation

### Prerequisites
- C++ Compiler (GCC, Clang, or MSVC)
- C++11 or higher support

### Compilation
g++ -std=c++11 -o leaderboard_sort main.cpp
./leaderboard_sort

## 💻 Usage

1. Run the executable
2. Enter number of players
3. Input player scores
4. Choose sorting algorithm from menu
5. View sorted leaderboard and performance metrics
6. Compare different algorithms with same dataset

## 📈 Sample Output

Enter the number of players: 5
Enter 5 scores: 85 42 93 61 77

GAMING LEADERBOARD SORTING
1. Bubble Sort
2. Insertion Sort
...
Choose sorting method: 1

Original scores: 85 42 93 61 77 
Leaderboard (Bubble Sort): 93 85 77 61 42 
Time taken: 45 microseconds
Number of swaps: 8
Number of comparisons: 10

## 🏆 Algorithm Selection Guide

| Scenario | Recommended Algorithm |
|----------|---------------------|
| Small datasets (<50) | Insertion Sort |
| Medium datasets | Quick Sort / Shell Sort |
| Large integer datasets | Radix Sort |
| Uniform score distribution | Bucket Sort |
| Memory constraints | Selection Sort |
| Educational purposes | Bubble Sort |

## 🔧 Technical Details

- **Sorting Order**: Descending (Highest to Lowest)
- **Data Type**: Integer scores
- **Stability**: Insertion and Bucket sorts are stable
- **In-place**: All except Bucket and Radix sorts
- **Global Counters**: Track swaps and comparisons

## 📝 Notes

- All algorithms modified for descending order sorting
- Performance metrics reset before each algorithm execution
- Original array preserved for multiple algorithm testing
- Time measured using high-resolution clock

## 👨‍💻 Development

Contributions welcome! Feel free to:
- Add more sorting algorithms
- Implement graphical performance visualization
- Add support for different data types
- Enhance the user interface

## 📄 License

This project is open source and available under the MIT License.

---

**Happy Coding! 🎮🏆**
