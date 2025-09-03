#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> arr = {1,1,1,1,1,3,3,4,4,6,6,6,7,7};
	int n = arr.size();
	int k = 1;
	for(int i = 1;i<n;i++){
		if(arr[i]!=arr[i-1]){
			arr[k]=arr[i];
			k++;
		}
	}
	cout<<"Array after removing duplicates = "<<endl;
	for(int i = 0;i<k;i++){
		cout<<arr[i]<<", ";
	}
	return 0;
}
