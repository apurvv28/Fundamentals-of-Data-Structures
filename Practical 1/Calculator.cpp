#include <iostream>
using namespace std;

float add(float a, float b){
	return a + b;
}

float sub(float a, float b){
	return a - b;
}

float mul(float a, float b){
	return a * b;
}

float div(float a, float b){
	return a / b;
}

int main(){
	int ch;
	float a, b, res;
	while(true){
	cout<< "Enter first number = "<<endl;
	cin>>a;
	cout<< "Enter second number = "<<endl;
	cin>>b;
	cout<< "Select an option (0,1,2,3,4) : "<<endl;
	cout<< "0. Addition"<<endl;
	cout<< "1. Subtraction"<<endl;
	cout<< "2. Multiplication"<<endl;
	cout<< "3. Division"<<endl;
	cout<< "4. Exit"<<endl;
	cin>>ch;
	switch(ch){
		case 0: 
		res = add(a,b);
		cout<<"The addition is "<<res<<endl;
		break;
		case 1:
		res = sub(a,b);
		cout<<"The subtraction is "<<res<<endl;
		break;
		case 2:
		res = mul(a,b);
		cout<<"The multiplication is "<<res<<endl;
		break;
		case 3:
		res = div(a,b);
		cout<<"The division is "<<res<<endl;
		break;
		case 4:
		break;
	}
	return 0;
}
}
