#include <iostream>
using namespace std;

int binary(int arr[], int size, int target){
	int left = 0;
	int right = size-1;
	while(left<=right){
		int mid = (left+right)/2;
		if(arr[mid] == target){
			return mid;
		}
		else if(arr[mid]<target){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return -1;
}

int main(){
	int arr[]={10,20,30,40,50,60,70};
	int size=7;
	int t=50;
	int res = binary(arr,size,t);
	if(res==-1){
		cout<<"Target not found"<<endl;
	}
	else{
		cout<<"The index of target element is "<<res<<endl;
	}
	return 0;
}
