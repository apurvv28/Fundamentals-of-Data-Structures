#include<iostream>
using namespace std;

void selection(int arr[], int n){
	for(int i = 0;i<n-1;i++){
		int min = i;
		for(int j = i+1;j < n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
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
	selection(arr,n);
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
