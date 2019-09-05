/*

Given a set of positive numbers, find if we can partition it into 
two subsets such that the sum of elements in both the subsets is equal.

Example 1:
    Input: {1, 2, 3, 4}
    Output: True
    Explanation: The given set can be partitioned into two subsets with equal sum: {1, 4} & {2, 3}

Example 2:
    Input: {1, 1, 3, 4, 7}
    Output: True
    Explanation: The given set can be partitioned into two subsets with equal sum: {1, 3, 4} & {1, 7}

Example 3:
    Input: {2, 3, 4, 6}
    Output: False
    Explanation: The given set cannot be partitioned into two subsets with equal sum.

*/


#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > memo;

// Top-down
int canPartition(vector<int>& subset, int sum, int index) {
    if(index >= subset.size() or sum < 0) {
        return 0;
    }
    
    if(sum == 0) {
        return 1;
    }
    
    if(memo[index][sum] == -1) {
        memo[index][sum] = max(canPartition(subset, sum, index+1), canPartition(subset, sum-subset[index], index+1));
    }
    
    return memo[index][sum];
                          
}


// Bottom-up
int canPartition(vector<int>& subset, int sum) {
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
    int s = 0;
    for(int i : subset) {
        s += i;
    }
    
    if(s%2) {
        cout << "Cannot Partition";
        return 0;
    }
    memo.resize(subset.size(), vector<int>(s/2+1, -1));
    cout << "Partition: " << canPartition(subset, s/2);
    return 0;
}