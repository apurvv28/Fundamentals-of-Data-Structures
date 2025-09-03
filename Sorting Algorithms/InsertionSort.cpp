#include<iostream>
using namespace std;

void insertion(int arr[], int n){
	for(int i = 1; i<n;i++){
		int key = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main(){
	int arr[]={23,45,12,98,45,9,11,61,37};
	int n = 9;
	cout<<"Before Sorting"<<endl;
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	cout<<"After Sorting"<<endl;
	insertion(arr,n);
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
