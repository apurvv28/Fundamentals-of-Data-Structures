#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int st, int mid, int end){
	vector<int> temp;
	int i = st;
	int j = mid+1;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}
		else{
			temp.push_back(arr[j]);
			j++;
		}
	}
	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=end){
		temp.push_back(arr[j]);
		j++;
	}
	for(int k = 0;k<temp.size();k++){
		arr[k+st]=temp[k];
	}
}

void mergesort(int arr[], int st, int end){
	if(st<end){
		int mid = st + (end - st)/2 ;
		mergesort(arr, st, mid);
		mergesort(arr, mid+1, end);
		merge(arr, st, mid, end);
	}		
}

int main(){
	int arr[]={23,45,12,98,45,9,11,61,37};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Before Sorting"<<endl;
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	cout<<"After Sorting"<<endl;
	mergesort(arr,0, n-1);
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
