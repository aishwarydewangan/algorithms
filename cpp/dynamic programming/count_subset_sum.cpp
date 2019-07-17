/*

Given a set of positive numbers, find the total number of subsets whose sum is equal to a given number ‘S’.

Example 1:
    Input: {1, 1, 2, 3}, S=4
    Output: 3
    The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
    Note that we have two similar sets {1, 3}, because we have two '1' in our input.

Example 2:
    Input: {1, 2, 7, 1, 5}, S=9
    Output: 3
    The given set has '3' subsets whose sum is '4': {2, 7}, {1, 7, 1}, {1, 2, 1, 5}

*/

#include <bits/stdc++.h>

using namespace std;

// Brute-force
// int partition(vector<int>& subset, int index, int sum) {
    
//     if(sum == 0) {
//         return 1;
//     }
    
//     if(index >= subset.size() or sum < 0) {
//         return 0;
//     }
    
//      return (partition(subset, index+1, sum-subset[index]) + partition(subset, index+1, sum));
// }

vector<vector<int>> memo;

// Top-down
int partition(vector<int>& subset, int index, int sum) {
    
    if(sum == 0) {
        return 1;
    }
    
    if(index >= subset.size() or sum < 0) {
        return 0;
    }
    
    if(memo[index][sum] == -1) {
        memo[index][sum] = partition(subset, index+1, sum-subset[index]) + partition(subset, index+1, sum);
    }
    
     return memo[index][sum];
}

int main() {
    vector<int> subset = {1, 2, 3, 4};
    int sum = 4;
    memo.resize(subset.size(), vector<int>(sum+1, -1));
    cout << "Count of Subset Sum: " << partition(subset, 0, sum);
    return 0;
}