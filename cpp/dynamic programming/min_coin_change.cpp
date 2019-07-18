/*

Given an infinite supply of ‘n’ coin denominations and a total money amount, we are asked to find 
the minimum number of coins needed to make up that amount.

Example:
    Denominations: {1,2,3}
    Total amount: 5
    Output: 2
    Explanation: We need minimum of two coins {2,3} to make a total of '5'

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int minCoins(vector<int>& coins, int amount, int index) {
    if(index == coins.size()) {
        if(amount == 0)
            return 0;
        return INT_MAX;
    }
    
    if(memo[index][amount] == -1) {
        int c1 = INT_MAX;
    
        if(coins[index] <= amount) {
            c1 = minCoins(coins, amount-coins[index], index);
            if(c1 != INT_MAX) {
                c1 += 1;
            }
        }

        int c2 = minCoins(coins, amount, index+1);

        memo[index][amount] = min(c1, c2);
    }
    
    return memo[index][amount];
}

int main() {
    vector<int> coins = {270,373,487,5,62};
    int amount = 8121;
    memo.resize(coins.size(), vector<int>(amount+1, -1));
    cout << "Minimum Coins required to make " << amount << ": " << minCoins(coins, amount, 0);
    return 0;
}