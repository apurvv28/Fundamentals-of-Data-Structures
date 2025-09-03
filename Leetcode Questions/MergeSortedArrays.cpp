#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<int> arr1 = {1,2,3,4,5};
	vector<int> arr2 = {6,7,8,9,10};
	int n = arr1.size();
	int m = arr2.size();
	int t = m + n;
	for(int j=0,i=m;i<t;i++){
		arr1[i]=arr2[j];
		j++;
	}
	sort(arr1.begin(),arr1.end());
	for(int i = 0;i<t;i++){
		cout<<arr1[i]<<", ";
	}
	return 0;
}
