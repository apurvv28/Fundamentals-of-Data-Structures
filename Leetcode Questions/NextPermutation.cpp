#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n-2;
    while(i>=0 && nums[i]>=nums[i+1]){
            i--;
    }
    if(i>=0){
    	int j = n-1;
        while(nums[j]<=nums[i]){
            j--;
        }
        swap(nums[i],nums[j]);
            
    }
    reverse(nums.begin()+i+1, nums.end());
}

int main(){
	vector<int> arr = {1,3,2};
	int n = arr.size();
	cout<<"Array before next permutation = ";
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<", ";
	}
	nextPermutation(arr);
	cout<<endl<<"After Next Permutation = ";
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<", ";
	}
}
