#include <iostream>
using namespace std;

void add2Mul(){
	const int maximum = 100;
	int poly1[maximum + 1] = {0};
	int poly2[maximum + 1] = {0};
	int result[2 * maximum + 1] = {0};
	 
	poly1[0] = 2;
	poly1[1] = 5;
	poly1[2] = 3;
	
	poly2[0] = 4;
	poly2[1] = 4;
	poly2[2] = 2;
	
	for(int i = 0; i < maximum; i++){
		for(int j = 0; j < maximum; j++){
			result[i+j] += poly1[i] * poly2[j];
		}
	}
	
	cout<<"Resultant Polynomial"<<endl;
	for(int i=4;i>=0;i--){
		if(result[i]!=0){
			cout<<result[i];
			if(i>0) cout<<"x^"<<i;
			if(i!=0) cout<<"+";
		}
	}
	cout<<endl;
}

int main(){
	add2Mul();
	return 0;
}
