#include<iostream>
#include<vector>
using namespace std;

vector<int> TwoSum(vector<int> arr, int target){
	int n = arr.size();
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(arr[j]+arr[i]==target){
				return {i,j};
			}
		}
	}
	return {};
}

int main(){
	vector<int> arr={1,2,3,4,5,6,7,8};
	int target = 15;
	vector<int> res = TwoSum(arr,target);
	int n = res.size();
	for(int i = 0;i<n;i++){
		cout<<res[i]<<"\t";
	}
	return 0;
}
