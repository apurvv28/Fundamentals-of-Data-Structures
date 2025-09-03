#include <iostream>
#include <cmath>
using namespace std;

int fibosearch(int arr[], int size, int target){
	int fib2=0;
	int fib1=1;
	int fib=fib1+fib2;
	
	while(fib<size){
		fib2=fib1;
		fib1=fib;
		fib=fib1+fib2;
	}
	
	int offset = 0;
	
	while(fib>1){
		int i = min(offset+fib2,size-1);
		if(arr[i]>target){
			fib=fib2;
			fib1=fib1-fib2;
			fib2=fib-fib1;
		}
		else if(arr[i]<target){
			fib=fib1;
			fib1=fib2;
			fib2=fib-fib1;
			offset = i;
		}
		else{
			return i;
		}
	}
	return -1;
}

int main(){
	int arr[]={10,20,30,40,50,60,70};
	int size=7;
	int t=50;
	int res = fibosearch(arr,size,t);
	if(res==-1){
		cout<<"Target not found"<<endl;
	}
	else{
		cout<<"The index of target element is "<<res<<endl;
	}
	return 0;
}
