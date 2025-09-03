#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majority(vector<int> &arr, int n){
	sort(arr.begin(),arr.end());
	return arr[n/2];
}
int main(){
	vector<int> arr = {1,1,3,4,4,4,4,4,4,6,6};
	int n = arr.size();
	int res = majority(arr,n);
	cout<<"Majority Element = "<<res;
	return 0;
}
