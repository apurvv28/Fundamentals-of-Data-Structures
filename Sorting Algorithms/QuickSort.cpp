#include<iostream>
using namespace std;

int partition(int arr[], int st, int end){
	int i = st-1;
	int pivot = arr[end];
	for(int j = st; j<end;j++){
		if(arr[j] <= pivot){
			i++;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	i++;
	int temp = arr[end];
	arr[end] = arr[i];
	arr[i] = temp;
	return i;
}

void quicksort(int arr[], int st, int end){
	if(st<end){
	int pI = partition(arr,st,end);
	quicksort(arr,st,pI-1);
	quicksort(arr,pI+1,end);
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
	quicksort(arr,0,n-1);
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
