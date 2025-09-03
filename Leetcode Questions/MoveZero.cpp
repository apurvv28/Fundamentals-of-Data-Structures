#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        for(int j = 0;j<n;j++){
        	if(arr[j]!=0){
        		swap(arr[i],arr[j]);
        		i++;
			}
		}
	}
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    sol.moveZeroes(nums);

    cout << "After:  ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}

