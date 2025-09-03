#include <iostream>
using namespace std;

int sentinel(int arr[], int size, int target){
	int last = arr[size-1];
	arr[size-1] = target;
	int i = 0;
	while(arr[i]!=target){
		i++;
	}
	arr[size-1] = last;
	if(i<size-1 || arr[size-1] == target){
		return i;
	}
	return -1;
}

int main(){
	int arr[]={10,20,30,40,50,60,70};
	int size=7;
	int t=50;
	int res = sentinel(arr,size,t);
	if(res==-1){
		cout<<"Target not found"<<endl;
	}
	else{
		cout<<"The index of target element is "<<res<<endl;
	}
	return 0;
}
