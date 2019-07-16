/*

Given a set of positive numbers, determine if there exists a subset whose sum is equal to a given number ‘S’.

Example 1:
    Input: {1, 2, 3, 7}, S=6
    Output: True
    The given set has a subset whose sum is '6': {1, 2, 3}

Example 2:
    Input: {1, 2, 7, 1, 5}, S=10
    Output: True
    The given set has a subset whose sum is '10': {1, 2, 7}

Example 3:
    Input: {1, 3, 4, 8}, S=6
    Output: False
    The given set does not have any subset whose sum is equal to '6'.

*/


#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > memo;

// Top-down
int isSubset(vector<int>& subset, int sum, int index) {
    if(index >= subset.size() or sum < 0) {
        return 0;
    }
    
    if(sum == 0) {
        return 1;
    }
    
    if(memo[index][sum] == -1) {
        memo[index][sum] = max(isSubset(subset, sum, index+1), isSubset(subset, sum-subset[index], index+1));
    }
    
    return memo[index][sum];
                          
}


// Bottom-up
int isSubset(vector<int>& subset, int sum) {
    int n = subset.size();
    
    for(int i = 0; i < n; i++) {
        memo[i][0] = 1;
    }
    
    for(int i = 1; i <= sum; i++) {
        memo[0][i] = (i == subset[0]);
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(subset[i] <= j) {
                memo[i][j] = max(memo[i-1][j], memo[i-1][j-subset[i]]);
            } else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    return memo[n-1][sum];
}

int main() {
    vector<int> subset = {1, 3, 5, 15};
    int sum = 5;
    memo.resize(subset.size(), vector<int>(sum+1, -1));
    cout << "Subset: " << isSubset(subset, sum);
    return 0;
}