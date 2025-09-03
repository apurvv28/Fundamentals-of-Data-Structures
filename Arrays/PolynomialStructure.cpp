#include <iostream>
using namespace std;

struct Term{
	int coeff;
	int exp;
};
void polyStruct(){
	const int MAX_TERMS = 100;
	Term poly[MAX_TERMS];
	int n = 4;
	poly[0] = {4,3};
	poly[1] = {6,2};
	poly[2] = {2,1};
	poly[3] = {3,0};
	
	cout<<"Structure Representation of Polynomial"<<endl;
	for(int i = 0; i < n; i++){
		cout << poly[i].coeff << "x^" << poly[i].exp;
        if (i != n-1) cout << " + ";
	}
	cout<<endl;
}

int main(){
	polyStruct();
	return 0;
}
