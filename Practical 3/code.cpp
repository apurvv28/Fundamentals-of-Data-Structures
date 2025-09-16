// Implement basic array operations such as insert, delete, and merge, while simulating a 2D array using a single-dimensional array to optimize space (using both row-major and column-major formats). Use pointer arithmetic to print memory addresses of elements, helping you understand how arrays are stored in memory.

#include <iostream>
using namespace std;

class Array2D {
    int *data;
    int rows, cols, size;
public:
    Array2D(int r, int c){
        rows=r; 
        cols=c;
        size=rows*cols;
        data=new int[size];
        for (int i=0; i<size; i++){
            data[i]=0;
        } 
    }

    int rowMajorIndex(int i, int j){
        return i*cols+j;
    }

    int colMajorIndex(int i, int j){
        return j*rows+i;
    }

    void insertRowMajor(int i, int j, int val){
        int index=rowMajorIndex(i, j);
        data[index]=val;
    }

    void insertColMajor(int i, int j, int val){
        int index=colMajorIndex(i, j);
        data[index]=val;
    }

    void deleteRowMajor(int i, int j){
        int index=rowMajorIndex(i, j);
        data[index]=0;
    }

    void printRowMajor(){
        cout <<endl<<"Row-Major Layout:"<<endl;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                int idx=rowMajorIndex(i, j);
                cout<<data[idx]<<"("<<(data + idx)<<")\t";
            }
            cout<<endl;
        }
    }

    void printColMajor(){
        cout<<"\nColumn-Major Layout:"<<endl;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                int idx = colMajorIndex(i, j);
                cout<<data[idx]<<"("<<(data + idx)<<")\t";
            }
            cout<<endl;
        }
    }

    void inputElementsRowMajor(){
        cout << "Enter elements for a " << rows << "x" << cols << " array (row-wise):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val;
                cout << "Element (" << i << "," << j << "): ";
                cin >> val;
                insertRowMajor(i, j, val);
            }
        }
    }

    static Array2D merge(Array2D &a, Array2D &b){
        int newRows=a.rows +b.rows;
        int newCols=max(a.cols, b.cols);
        Array2D result(newRows, newCols);

        for (int i = 0; i < a.rows; i++) {
            for (int j = 0; j < a.cols; j++) {
                result.insertRowMajor(i, j, a.data[a.rowMajorIndex(i, j)]);
            }
        }
        for (int i = 0; i < b.rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                result.insertRowMajor(i + a.rows, j, b.data[b.rowMajorIndex(i, j)]);
            }
        }
        return result;
    }
    ~Array2D(){ 
    delete[] data;
    }
};

int main() {
    cout<<"Enter number of rows and columns respectively: "<<endl;
    int r, c;
    cin>>r>>c;
    Array2D arr(3, 3);
    arr.inputElementsRowMajor();

    arr.printRowMajor();
    arr.printColMajor();

    cout << "\nDeleting element in row-major..." << endl;
    arr.deleteRowMajor(1, 0);

    arr.printRowMajor();

    cout << "\nMerging two arrays:" << endl;
    Array2D arr2(2, 3);
    arr2.insertRowMajor(0, 0, 100);
    arr2.insertRowMajor(1, 1, 200);

    Array2D merged = Array2D::merge(arr, arr2);
    merged.printRowMajor();

    return 0;
}
