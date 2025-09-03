#include <iostream>
using namespace std;

void polyArray(){
	const int MAX_TERMS = 100;
	int poly[MAX_TERMS + 1] = {0};
	poly[0] = 2;
	poly[1] = 5;
	poly[2] = 3;
	
	cout<<"Array Representation of Polynomial"<<endl;
	for(int i=3;i>=0;i--){
		if(poly[i]!=0){
			cout<<poly[i];
			if(i>0) cout<<"x^"<<i;
			if(i!=0) cout<<"+";
		}
	}
	cout<<endl;
}

int main(){
	polyArray();
	return 0;
}
