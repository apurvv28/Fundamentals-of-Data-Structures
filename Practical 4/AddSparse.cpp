#include <iostream>
using namespace std;
struct Triple{
    int row;
    int col;
    int value;
};
int main(){
    int r1, r2, c1, c2;
    cout<<"Enter number of rows and columns of first matrix respectively: "<<endl;
    cin>>r1>>c1;
    cout<<"Enter number of rows and columns of second matrix respectively: "<<endl;
    cin>>r2>>c2;
    if(c1!=c2||r1!=r2){
        cout<<"Matrix multiplication not possible"<<endl;
        return 0;
    }
    int matrix1[r1][c1], matrix2[r2][c2];
    cout<<"Enter elements of first matrix: "<<endl;
    for(int i = 0;i < r1;i++){
        for(int j = 0; j<c1; j++){
            cin>>matrix1[i][j];
        }
    }
    cout<<"Enter elements of second matrix: "<<endl;
    for(int i = 0;i < r2;i++){
        for(int j = 0; j<c2; j++){
            cin>>matrix2[i][j];
        }
    }
    int nz1=0, nz2=0;
    for(int i = 0;i < r1;i++){
        for(int j = 0; j<c1; j++){
            if(matrix1[i][j]!=0){
                nz1++;
            }
            if(matrix2[i][j]!=0){
                nz2++;
            }
        }
    }
    Triple sparse1[nz1+1], sparse2[nz2+1];
    sparse1[0].row = r1;
    sparse1[0].col = c1;
    sparse1[0].value = nz1;
    sparse2[0].row = r2;
    sparse2[0].col = c2;
    sparse2[0].value = nz2;

    int k = 1;
    for(int i = 0;i< r1;i++){
        for(int j =0;j< c1;j++){
            if(matrix1[i][j]!=0){
                sparse1[k].row = i;
                sparse1[k].col = j;
                sparse1[k].value = matrix1[i][j];
                k++;
            }
        }
    }
    k = 1;
    for(int i = 0;i< r2;i++){
        for(int j =0;j< c2;j++){
            if(matrix2[i][j]!=0){
                sparse2[k].row = i;
                sparse2[k].col = j;
                sparse2[k].value = matrix2[i][j];
                k++;
            }
        }
    }
    cout<<"The sparse matrix 1 is: "<<endl;
    cout << "Row\tCol\tValue" <<endl;
    for(int i = 1;i <= nz1;i++){
        cout<<sparse1[i].row<<"\t "<<sparse1[i].col<<" \t"<<sparse1[i].value<<endl;
    }
    cout<<"The sparse matrix 2 is: "<<endl;
    cout << "Row\tCol\tValue" <<endl;
    for(int i = 1;i <= nz2;i++){
        cout<<sparse2[i].row<<"\t "<<sparse2[i].col<<" \t"<<sparse2[i].value<<endl;
    }

    Triple result[nz1+nz2+1];
    result[0].row = r1;
    result[0].col = c1;
    int p=1;
    for(int i=1;i<=nz1;i++){
        result[p]=sparse1[i];
        p++;
    }
    for(int i=1;i<=nz2;i++){
        bool found=false;
        for(int j=1;j<p;j++){
            if(sparse2[i].row==result[j].row && sparse2[i].col==result[j].col){
                result[j].value+=sparse2[i].value;
                found=true;
                break;
            }
        }
        if(!found){
            result[p]=sparse2[i];
            p++;
        }
    }
    result[0].value=p-1;
    cout<<"The resultant sparse matrix after addition is: "<<endl;
    cout << "Row\tCol\tValue" <<endl;
    for(int i = 1;i < p;i++){
        cout<<result[i].row<<"\t "<<result[i].col<<" \t"<<result[i].value<<endl;
    }
    return 0;
}