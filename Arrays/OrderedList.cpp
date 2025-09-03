#include <iostream>
using namespace std;

int main(){
	int list[10]={10,20,30,40,50};
	int size=5;
	int newE=25;
	int pos=0;
	while(pos<size&&list[pos]<newE){
		pos++;
	}
	for(int i=size;i>pos;i--){
		list[i]=list[i-1];
	}
	list[pos]=newE;
	size++;
	
	for(int i=0;i<size;i++){
		cout<<list[i]<<endl;
	}
	return 0;
}
