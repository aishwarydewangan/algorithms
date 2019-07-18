/*

Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a 
capacity ‘C’. The goal is to get the maximum profit from the items in the knapsack. The only difference 
between the 0/1 Knapsack problem and this problem is that we are allowed to use an unlimited quantity of 
an item.

*/

#include <bits/stdc++.h>

using namespace std;

// Brute-force 1
int profit_bf1(vector<int>& weights, vector<int>& prices, int capacity, int index) {
    if(index >= prices.size() or capacity <= 0) {
        return 0;
    }
    
    int i = 0, res = 0;
    
    while(i*weights[index] <= capacity) {
        int p = i*prices[index] + profit_bf1(weights, prices, capacity-i*weights[index], index+1);
        res = max(res, p);
        i++;
    }
    
    return res;
}

// Brute-force 2
int profit_bf2(vector<int>& weights, vector<int>& prices, int capacity, int index) {
    if(index >= prices.size() or capacity <= 0) {
        return 0;
    }
    
    int profit1 = 0;
    
    if(weights[index] <= capacity) {
        profit1 = prices[index] + profit_bf2(weights, prices, capacity-weights[index], index);
    }
    
    int profit2 = profit_bf2(weights, prices, capacity, index+1);
    
    return max(profit1, profit2);
}

vector<vector<int>> memo;

// Top-down 1
int profit_td1(vector<int>& weights, vector<int>& prices, int capacity, int index) {
    if(index >= prices.size() or capacity <= 0) {
        return 0;
    }
    
    if(memo[index][capacity] != -1) {
        return memo[index][capacity];
    }
    
    int i = 0, res = 0;
    
    while(i*weights[index] <= capacity) {
        int p = i*prices[index] + profit_td1(weights, prices, capacity-i*weights[index], index+1);
        res = max(res, p);
        i++;
    }
    
    return (memo[index][capacity] = res);
}

// Top-down 2
int profit_td2(vector<int>& weights, vector<int>& prices, int capacity, int index) {
    if(index >= prices.size() or capacity <= 0) {
        return 0;
    }
    
    if(memo[index][capacity] != -1) {
        return memo[index][capacity];
    }
    
    int profit1 = 0;
    
    if(weights[index] <= capacity) {
        profit1 = prices[index] + profit_td2(weights, prices, capacity-weights[index], index);
    }
    
    int profit2 = profit_td2(weights, prices, capacity, index+1);
    
    return (memo[index][capacity] = max(profit1, profit2));
}

int main() {
    
    vector<int> weights = {1, 3, 4, 5};
    
    vector<int> prices = {15, 50, 60, 90};
    
    int capacity = 8;
    
    memo.resize(prices.size(), vector<int>(capacity+1, -1));
    
    cout << "Profit: " << profit_td2(weights, prices, capacity, 0);
    
    return 0;
}