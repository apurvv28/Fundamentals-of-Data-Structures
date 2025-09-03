#include <iostream>
using namespace std;

int fib(int n){
	if(n <= 1){
		return n;
	}
		return fib(n-1)+fib(n-2);
}

int main(){
	int n;
	cout<<"Enter a value "<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
	cout<<fib(i)<<endl;
	}
	return 0;
}
