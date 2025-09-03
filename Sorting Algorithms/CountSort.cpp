#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countsort(vector<int>& arr){
    int n = arr.size();
    int max = *max_element(arr.begin(), arr.end());
    vector<int> count(max+1,0);
    for(int i = 0; i<n ; i++){
    	count[arr[i]]++;
	}
	//Cummulative Sequence
	for(int i=1;i<=max;i++){
		count[i] += count[i-1];
	}
	vector<int> output(n);
	for(int i = n-1; i>=0; i--){
		output[count[arr[i]]-1] = arr[i];
		count[arr[i]]--;
	}
	arr=output;
}
int main(){
    vector<int> arr;
    arr.push_back(23);
    arr.push_back(45);
    arr.push_back(12);
    arr.push_back(98);
    arr.push_back(45);
    arr.push_back(9);
    arr.push_back(11);
    arr.push_back(61);
    arr.push_back(37);
    cout << "Before Sorting" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    countsort(arr);
    
    cout << "After Sorting" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
