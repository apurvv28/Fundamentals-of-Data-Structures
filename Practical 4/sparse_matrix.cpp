#include <iostream>
using namespace std;

struct Triple{
    int row;
    int col;
    int value;
};

int main(){
    int rows, cols, nz=0;
    cout<<"Enter number of rows and columns respectively: "<<endl;
    cin>>rows>>cols;
    int matrix[rows][cols];
    cout<<"Enter elemens of matrix: "<<endl;
    for(int i = 0;i < rows;i++){
        for(int j = 0; j<cols; j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                nz++;
            }
        }
    }

    Triple sparse[nz+1];
    sparse[0].row = rows;
    sparse[0].col = cols;
    sparse[0].value = nz;

    int k = 1;
    for(int i = 0;i< rows;i++){
        for(int j =0;j< cols;j++){
            if(matrix[i][j]!=0){
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = matrix[i][j];
                k++;
            }
        }
    }

    cout<<"The sparse matrix is: "<<endl;
    cout << "Row\tCol\tValue" <<endl;
    for(int i = 1;i <= nz;i++){
        cout<<sparse[i].row<<"\t "<<sparse[i].col<<" \t"<<sparse[i].value<<endl;
    }

    Triple simple[nz+1];
    simple[0].row = sparse[0].col;
    simple[0].col = sparse[0].row;
    simple[0].value = sparse[0].value;

    int t = 1;
    for(int col = 0; col < cols; col++) {
        for(int i = 1; i <= nz; i++) {
            if(sparse[i].col == col) {
                simple[t].row = sparse[i].col;
                simple[t].col = sparse[i].row;
                simple[t].value = sparse[i].value;
                t++;
            }
        }
    }

    cout << "The simple transpose sparse matrix is:" << endl;
    cout << "Row\tCol\tValue" << endl;
    for(int i = 1; i <= nz; i++) {
        cout << simple[i].row << "\t" << simple[i].col << "\t" << simple[i].value << endl;
    }

    Triple fast[nz + 1];
    fast[0] = {cols, rows, nz};

    int count[cols] = {0}, index[cols];

    for (int i = 1; i <= nz; i++){
        count[sparse[i].col]++;
        }

    index[0] = 1;
    for (int i = 1; i < cols; i++){
        index[i] = index[i - 1] + count[i - 1];
    }

    for (int i = 1; i <= nz; i++) {
        int col = sparse[i].col;
        int pos = index[col]++;
        fast[pos] = {sparse[i].col, sparse[i].row, sparse[i].value};
    }

    cout << "The fast transpose sparse matrix is:" << endl;
    cout << "\nRow\tCol\tValue\n";
    for (int i = 1; i <= nz; i++){
        cout << fast[i].row << "\t" << fast[i].col << "\t" << fast[i].value << endl;
    }
    return 0;
}