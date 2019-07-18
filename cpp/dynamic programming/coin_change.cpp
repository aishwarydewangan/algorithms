/*

Given an infinite supply of ‘n’ coin denominations and a total money amount, we are asked to find 
the total number of distinct ways to make up that amount.

Example:
    Denominations: {1,2,3}
    Total amount: 5
    Output: 5
    Explanation: There are five ways to make the change for '5', here are those ways:
      1. {1,1,1,1,1} 
      2. {1,1,1,2} 
      3. {1,2,2}
      4. {1,1,3}
      5. {2,3}

*/

#include <bits/stdc++.h>

using namespace std;

// Brute-force
int ways_bf(vector<int>& coins, int amount, int index) {
    if(index == coins.size()) {
        return (amount == 0);
    }
    
    int way1 = 0;
    
    if(coins[index] <= amount)
        way1 = ways_bf(coins, amount-coins[index], index);
    
    int way2 = ways_bf(coins, amount, index+1);
    
    return (way1+way2);
}

vector<vector<int>> memo;

// Top-down
int ways_td(vector<int>& coins, int amount, int index) {
    if(index == coins.size()) {
        return (amount == 0);
    }
    
    if(memo[index][amount] != -1) {
        return memo[index][amount];
    }
    
    int way1 = 0;
    
    if(coins[index] <= amount)
        way1 = ways_td(coins, amount-coins[index], index);
    
    int way2 = ways_td(coins, amount, index+1);
    
    return (memo[index][amount] = (way1+way2));
}

int main() {
    vector<int> coins = {2, 5, 3, 6};
    int amount = 10;
    memo.resize(coins.size(), vector<int>(amount+1, -1));
    cout << "Ways to make " << amount << ": " << ways_td(coins, amount, 0);
    return 0;
}