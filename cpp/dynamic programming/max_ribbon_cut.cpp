/*

We are given a ribbon of length ‘n’ and a set of possible ribbon lengths. Now we need to cut the 
ribbon into the maximum number of pieces that comply with the above-mentioned possible lengths. Write a 
method that will return the count of pieces.

Example 1:
    n: 5
    Ribbon Lengths: {2,3,5}
    Output: 2
    Explanation: Ribbon pieces will be {2,3}.

Example 2:
    n: 7
    Ribbon Lengths: {2,3}
    Output: 3
    Explanation: Ribbon pieces will be {2,2,3}.

Example 3:
    n: 13
    Ribbon Lengths: {3,5,7}
    Output: 3
    Explanation: Ribbon pieces will be {3,3,7}.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int ribbon(vector<int>& coins, int amount, int index) {
    if(index == coins.size()) {
        if(amount == 0)
            return 0;
        return INT_MIN;
    }
    
    if(memo[index][amount] == -1) {
        int c1 = INT_MIN;
    
        if(coins[index] <= amount) {
            c1 = ribbon(coins, amount-coins[index], index);
            if(c1 != INT_MIN) {
                c1 += 1;
            }
        }

        int c2 = ribbon(coins, amount, index+1);

        memo[index][amount] = max(c1, c2);
    }
    
    return memo[index][amount];
}

int main() {
    vector<int> coins = {2, 3, 5};
    int amount = 5;
    memo.resize(coins.size(), vector<int>(amount+1, -1));
    cout << "Maximum Ribbon Cut: " << ribbon(coins, amount, 0);
    return 0;
}