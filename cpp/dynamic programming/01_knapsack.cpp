/*

Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. The goal is to get the maximum profit from the items in the knapsack. Each item can only be selected once.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

// Top-down
int profit(vector<int>& prices, vector<int>& weights, int capacity, int index) {
    if(index >= prices.size()) {
        return 0;
    }
    
    if(memo[index][capacity] != -1)
        return memo[index][capacity];
    
    int p1 = 0;
    
    if(capacity-weights[index] >= 0) {
        p1 = prices[index] + profit(prices, weights, capacity-weights[index], index+1);
    }
    
    int p2 = profit(prices, weights, capacity, index+1);
    
    return (memo[index][capacity] = max(p1, p2));
}


// Bottom-Up
int profit(vector<int>& prices, vector<int>& weights, int capacity) {
    int n = prices.size();
    
    for(int i = 0; i < n; i++)
        memo[i][0] = 0;
    
    for(int i = 0; i <= capacity; i++)
        if(weights[0] <= i)
            memo[0][i] = prices[0];
    
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= capacity; j++) {
            if(weights[i] <= j) {
                memo[i][j] = max(memo[i-1][j], prices[i] + memo[i-1][j-weights[i]]);
            } else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    return memo[n-1][capacity];
}

int main() {
    vector<int> p = {1, 6, 10, 16};
    vector<int> c = {1, 2, 3, 5};
    int capacity = 7;
    memo.resize(p.size(), vector<int>(capacity+1, -1));
    cout << profit(p, c, 7);
}