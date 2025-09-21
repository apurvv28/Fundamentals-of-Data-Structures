# Array2D: Simulating 2D Arrays Using a Single-Dimensional Array in C++

This C++ project demonstrates how to implement **basic array operations** (insert, delete, merge) using a **single-dimensional array** to simulate a 2D array. It also explores **row-major** and **column-major** memory layouts and uses **pointer arithmetic** to display memory addresses of elements.

---

## Features

- Create a 2D array using a single-dimensional array.
- Insert elements in **row-major** or **column-major** order.
- Delete elements from the array.
- Print array in **row-major** and **column-major** layouts along with memory addresses.
- Merge two arrays into a larger array.
- Demonstrates memory layout and pointer arithmetic.

---

## Class: `Array2D`

### Member Variables
- `int *data` – Pointer to dynamically allocated memory for storing array elements.
- `int rows, cols` – Number of rows and columns in the array.
- `int size` – Total number of elements (`rows * cols`).

### Member Functions
- `Array2D(int r, int c)` – Constructor to allocate memory and initialize elements to 0.
- `int rowMajorIndex(int i, int j)` – Computes the 1D index for row-major access.
- `int colMajorIndex(int i, int j)` – Computes the 1D index for column-major access.
- `void insertRowMajor(int i, int j, int val)` – Insert a value in row-major format.
- `void insertColMajor(int i, int j, int val)` – Insert a value in column-major format.
- `void deleteRowMajor(int i, int j)` – Deletes (sets to 0) an element in row-major format.
- `void printRowMajor()` – Prints the array in row-major format along with memory addresses.
- `void printColMajor()` – Prints the array in column-major format along with memory addresses.
- `void inputElementsRowMajor()` – Inputs elements from the user row-wise.
- `static Array2D merge(Array2D &a, Array2D &b)` – Merges two arrays into a new array.
- `~Array2D()` – Destructor to free dynamically allocated memory.

---

## Usage
>> Follow prompts to:

1. Enter the number of rows and columns.

2. Input array elements row-wise.

3. View row-major and column-major layouts with memory addresses.

4. Delete an element.

5. Merge two arrays and display the merged array.

>> Example Output
Enter number of rows and columns respectively:
3 3
Enter elements for a 3x3 array (row-wise):
Element (0,0): 1
Element (0,1): 2
Element (0,2): 3

Row-Major Layout:
1(0x600003600)  2(0x600003604)  3(0x600003608)

Column-Major Layout:
1(0x600003600)  2(0x600003604)  3(0x600003608)

Deleting element in row-major...
Row-Major Layout after deletion:
1(0x600003600)  2(0x600003604)  3(0x600003608)
0(0x600003610)  5(0x600003614)  6(0x600003618)


Merging two arrays:
1  2  3
0  5  6
100 0 0
0 200 0

>> Key Concepts Demonstrated
- Simulating 2D arrays using 1D arrays

- Row-major vs Column-major layouts

- Pointer arithmetic and memory addresses

- Array operations: insert, delete, merge

### Author
- Apurv Saktepar

### License
- This project is licensed under the MIT License.