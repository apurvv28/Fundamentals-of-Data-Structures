//Coin Change Problem using Greedy Algorithm
//Time Complexity: Worst Case = O(n log n) due to sorting, Best Case = Omega(n), Average Case = Theta(n log n)
//Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void coinChange(vector<int> coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    vector<int> count(coins.size(), 0);

    for (int i = 0; i < coins.size(); i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count[i]++;
        }
    }

    cout << "Coins used:\n";
    for (int i = 0; i < coins.size(); i++) {
        if (count[i] > 0) {
            cout << coins[i] << " x " << count[i] << endl;
        }
    }
}

int main() {
    int n, amount, result;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        if (coins[i] <= 0) {
            cout << "Invalid coin!" << endl;
            return 0;
        }
    }
    cout << "Enter amount to make change: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Invalid amount!" << endl;
        return 0;
    }
    coinChange(coins, amount);
    return 0;
}
