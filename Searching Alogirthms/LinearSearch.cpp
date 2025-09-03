#include <iostream>
using namespace std;

int linear(int arr[], int size, int target){
	for(int i = 0;i < size; i++){
		if(arr[i]==target){
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[]={10,20,30,40,50,60,70};
	int size=7;
	int t=50;
	int res = linear(arr,size,t);
	if(res==-1){
		cout<<"Target not found"<<endl;
	}
	else{
		cout<<"The index of target element is "<<res<<endl;
	}
	return 0;
}
