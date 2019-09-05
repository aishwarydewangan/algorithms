/*

The rod-cutting problem is the following:

Given a rod of length n inches and a table of prices pi for i = 1, 2,.....,n, determine the maximum 
revenue rn obtainable by cutting up the rod and selling the pieces. 

// CLRS Solution

#include <bits/stdc++.h>

using namespace std;

vector<int> prices = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 32, 40};

map<int, int> mp;

int cutRod(int n) {
	if(n == 0) {
		return 0;
	}

	if(mp[n] != 0) {
		return mp[n];
	}

	int q = INT_MIN;

	for(int i = 1; i <= n; i++) {
		q = max(q, prices[i]+cutRod(n-i));
	}

	mp[n] = q;

	return mp[n];
}

int main() {
	int n = 1;
	cout << "\nRod Size: " << n << "\nMax Price: " << cutRod(n);
}
*/

#include <bits/stdc++.h>

using namespace std;

// Brute-force
int profit_bf(vector<int>& lengths, vector<int>& prices, int length, int index) {
    if(index >= lengths.size()) {
        return 0;
    }
    
    int profit1 = 0;
    
    if(lengths[index] <= length) {
        profit1 = prices[index] + profit_bf(lengths, prices, length-lengths[index], index);
    }
    
    int profit2 = profit_bf(lengths, prices, length, index+1);
    
    return max(profit1, profit2);
}

vector<vector<int>> memo;

// Top-down
int profit_td(vector<int>& lengths, vector<int>& prices, int length, int index) {
    if(index >= lengths.size()) {
        return 0;
    }
    
    if(memo[index][length] != -1) {
        return memo[index][length];
    }
    
    int profit1 = 0;
    
    if(lengths[index] <= length) {
        profit1 = prices[index] + profit_td(lengths, prices, length-lengths[index], index);
    }
    
    int profit2 = profit_td(lengths, prices, length, index+1);
    
    return (memo[index][length] = max(profit1, profit2));
}

int main() {
    vector<int> lengths = {1, 2, 3, 4, 5};
    
    vector<int> prices = {2, 6, 7, 10, 13};
    
    int length = 5;
    
    memo.resize(prices.size(), vector<int>(length+1, -1));
    
    cout << "Profit: " << profit_td(lengths, prices, length, 0);
}