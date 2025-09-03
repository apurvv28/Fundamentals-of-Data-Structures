#include <iostream>
using namespace std;

int indexsequential(int arr[], int size, int target) {
    const int step = 3; 
    int indexSize = (size + step - 1) / step;  
    int indexValues[indexSize];  
    int indexPositions[indexSize]; 
    for (int i = 0, j = 0; i < size; i += step, j++) {
        indexValues[j] = arr[i];
        indexPositions[j] = i;
    }
    int start = 0;
    int end = size;
    for (int i = 0; i < indexSize; i++) {
        if (indexValues[i] >= target) {
            end = indexPositions[i] + 1;  
            start = (i == 0) ? 0 : indexPositions[i-1];
            break;
        }
    }
    for (int i = start; i < end; i++) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1;
}

int main() {
    int arr[]={10,20,30,40,50,60,70};
	int size=7;
	int t=50;
	int res = indexsequential(arr,size,t);
	if(res==-1){
		cout<<"Target not found"<<endl;
	}
	else{
		cout<<"The index of target element is "<<res<<endl;
	}
    return 0;
}
