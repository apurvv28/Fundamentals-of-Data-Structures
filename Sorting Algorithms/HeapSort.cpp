#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapsort(vector<int>& arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main(){
    vector<int> arr;
    arr.push_back(23);
    arr.push_back(45);
    arr.push_back(12);
    arr.push_back(98);
    arr.push_back(45);
    arr.push_back(9);
    arr.push_back(11);
    arr.push_back(61);
    arr.push_back(37);
    cout << "Before Sorting" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    heapsort(arr);
    
    cout << "After Sorting" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
