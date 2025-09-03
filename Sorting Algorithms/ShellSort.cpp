#include<iostream>
using namespace std;

void shell(int arr[], int n){
	int h = 1;
	while(h<n/3){
		h = 3*h+1; //Knuth's Formula
	}
	while(h>=1){
		for(int i = h;i < n;i++){
			int temp = arr[i];
			int j=i;
			while(j>=h && arr[j-h] > temp){
				arr[j] = arr[j-h];
				j-=h;
			}
			arr[j] = temp;
		}
		h = h/3;
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
	shell(arr,n);
	for(int i = 0;i < n;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
