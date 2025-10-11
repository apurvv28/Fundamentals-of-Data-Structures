#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float> arr, int n){
    for(int i = 1;i<n;i++){
        float key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void bucketSort(float arr[], int n){
    vector<float> buckets[n];
    for(int i = 0;i<n;i++){
        int index = arr[i] * n;
        buckets[index].push_back(arr[i]);
    }
    for(int i = 0;i<n;i++){
        insertionSort(buckets[i], buckets[i].size());
    }
    for(int i = 0, j = 0;i<n;i++){
        for(int k = 0;k<buckets[i].size();k++){
            arr[j++] = buckets[i][k];
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    float arr[n];
    cout<<"Enter elements (between 0 and 1): "<<endl;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    bucketSort(arr, n);
    cout<<"Sorted array: "<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}