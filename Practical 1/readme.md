# Divide and Conquer Multiplication Algorithms

This project demonstrates two approaches to large integer multiplication using divide and conquer techniques:

1. **Gauss Multiplication (Basic Divide & Conquer, 4 recursive calls)**
2. **Karatsuba Multiplication (Optimized Divide & Conquer, 3 recursive calls)**

Both codes measure:
- Recursive calls
- Multiplications
- Additions
- Digit count
- Execution time

---

## 🔹 Problem Statement
Given two integers `n1` and `n2`, multiply them efficiently using recursive divide-and-conquer strategies instead of the traditional `O(n^2)` multiplication.

---

## 🔹 1. Gauss Multiplication

### Algorithm
- Split both numbers into **high** and **low** parts.
- Recursively compute:
bd = b*d
bc = b*c
ad = a*d
ac = a*c

- Recombine using:
result = ac * 10^(2m) + (bc + ad) * 10^m + bd

### Characteristics
- Requires **4 recursive calls**.
- More multiplications compared to Karatsuba.
- Simpler to implement.

---

## 🔹 2. Karatsuba Multiplication

### Algorithm
- Split both numbers into **high** and **low** parts.
- Recursively compute:
bd = b*d
abcd = (a + c) × (b + d)
ac = a*c

- Recombine using:
result = ac * 10^(2m) + (abcd - ac - bd) * 10^m + bd


### Characteristics
- Requires only **3 recursive calls**.
- Fewer multiplications → faster for large numbers.
- Slightly more additions/subtractions.

---

## 🔹 Comparison of Tracked Analysis

| Metric             | Gauss Multiplication | Karatsuba Multiplication |
|--------------------|----------------------|---------------------------|
| Recursive Calls    | Higher (4 per level) | Lower (3 per level)       |
| Multiplications    | More                 | Fewer                     |
| Additions          | Fewer                | Slightly more             |
| Digit Count        | Similar              | Similar                   |
| Execution Time     | Slower               | Faster for large inputs   |

---

## 🔹 Time Complexity

### Gauss Multiplication
- Recurrence:  
`T(n) = 4T(n/2) + O(n)`  
- Using Master’s Theorem:  
`T(n) = O(n^2)`  
- **Best/Average/Worst:** All `O(n^2)` (same as schoolbook multiplication, but recursive).  

### Karatsuba Multiplication
- Recurrence:  
`T(n) = 3T(n/2) + O(n)`  
- Using Master’s Theorem:  
`T(n) = O(n^log2(3)) ≈ O(n^1.585)`  
- **Best/Average/Worst:** All `O(n^1.585)`.  

---

## 🔹 Space Complexity
Both algorithms use recursion:
- Depth of recursion = `O(log n)`  
- At each level, temporary values are stored → `O(n)` space for string/number splits  
- **Overall Space Complexity:** `O(n)`  

---

## 🔹 Example Output
Enter first number : 12345
Enter second number : 6789

Gauss Multiplication : 12345 x 6789 = 83810205
Recursive calls: 9
Multiplications: 5
Additions: 2
Digit count: 4
Execution time: 120 µs

Karatsuba Multiplication : 12345 x 6789 = 83810205
Recursive calls: 7
Multiplications: 3
Additions: 4
Digit count: 4
Execution time: 80 µs

---

## 🔹 Conclusion
- **Gauss Multiplication** is conceptually simpler but less efficient.  
- **Karatsuba Multiplication** reduces the number of recursive calls and multiplications, making it significantly faster for large numbers.  
- For very large integers (thousands of digits), Karatsuba and beyond (Toom-Cook, FFT-based methods) are the standard choices.

---