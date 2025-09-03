#include <iostream>
using namespace std;

void add2Mul(){
	const int MAX_TERMS = 100;
	int poly1[MAX_TERMS + 1] = {0};
	int poly2[MAX_TERMS + 1] = {0};
	int result[2 * MAX_TERMS + 1] = {0};
	 
	poly1[0] = 2;
	poly1[1] = 5;
	poly1[2] = 3;
	
	poly2[0] = 4;
	poly2[1] = 4;
	poly2[2] = 2;
	
	for(int i = 0; i < MAX_TERMS; i++){
		for(int j = 0; j < MAX_TERMS; j++){
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
