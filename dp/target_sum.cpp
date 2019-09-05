/*

Given a set of positive numbers and a target sum ‘S’. Each number should be assigned either a ‘+’ or ‘-’ sign. 
We need to find out total ways to assign symbols to make the sum of numbers equal to target ‘S’.

Example 1:
    Input: {1, 1, 2, 3}, S=1
    Output: 3
    Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} & {-1+1-2+3} & {+1+1+2-3}

Example 2:
    Input: {1, 2, 7, 1}, S=9
    Output: 2
    Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} & {-1+2+7+1}

*/

#include <bits/stdc++.h>

using namespace std;

// Brute-force
// int partition(vector<int>& subset, int index, int sum) {
    
//     if(index == subset.size()) {
//         return (sum == 0);
//     }
    
//     int p1 = partition(subset, index+1, sum);
    
//     int p2 = partition(subset, index+1, sum-subset[index]);
    
//     return (p1+p2);
// }

vector<vector<int>> memo;

// Top-down
int partition(vector<int>& subset, int index, int sum) {
    
    if(index == subset.size()) {
        return (sum == 0);
    }
    
    if(memo[index][sum] == -1) {
        int p1 = partition(subset, index+1, sum);
    
        int p2 = partition(subset, index+1, sum-subset[index]);
        
        memo[index][sum] = p1+p2;
    }
    
    return memo[index][sum];
}

int main() {
    vector<int> subset = {1, 2, 7, 1};
    int target = 9;
    int sum = 0;
    for(int s : subset) {
        sum += s;
    }
    memo.resize(subset.size(), vector<int>(((target+sum)/2)+1, -1));
    cout << "Target Sum: " << partition(subset, 0, ((target+sum)/2));
    return 0;
}