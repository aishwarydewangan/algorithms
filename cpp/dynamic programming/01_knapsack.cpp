/*

Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’. The goal is to get the maximum profit from the items in the knapsack. Each item can only be selected once.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int profit(vector<int>& prices, vector<int>& capacities, int capacity, int index) {
    if(index >= prices.size()) {
        return 0;
    }
    
    if(memo[capacity][index] != -1)
        return memo[capacity][index];
    
    int p1 = 0;
    
    if(capacity-capacities[index] >= 0) {
        p1 = prices[index] + profit(prices, capacities, capacity-capacities[index], index+1);
    }
    
    int p2 = profit(prices, capacities, capacity, index+1);
    
    return (memo[capacity][index] = max(p1, p2));
}

int main() {
    vector<int> p = {1, 6, 10, 16};
    vector<int> c = {1, 2, 3, 5};
    int capacity = 7;
    memo.resize(capacity+1, vector<int>(p.size(), -1));
    cout << profit(p, c, 7, 0);
}