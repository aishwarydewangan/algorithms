/*

Given a set of positive numbers, partition the set into two subsets with a minimum difference between their subset sums.

Example 1:
    Input: {1, 2, 3, 9}
    Output: 3
    Explanation: We can partition the given set into two subsets where minimum absolute difference 
    between the sum of numbers is '3'. Following are the two subsets: {1, 2, 3} & {9}.

Example 2:
    Input: {1, 2, 7, 1, 5}
    Output: 0
    Explanation: We can partition the given set into two subsets where minimum absolute difference 
    between the sum of number is '0'. Following are the two subsets: {1, 2, 5} & {7, 1}.

Example 3:
    Input: {1, 3, 100, 4}
    Output: 92
    Explanation: We can partition the given set into two subsets where minimum absolute difference 
    between the sum of numbers is '92'. Here are the two subsets: {1, 3, 4} & {100}.

*/

#include <bits/stdc++.h>

using namespace std;

// Brute-force
// int partition(vector<int>& subset, int index, int sum1, int sum2) {
//     if(index == subset.size()) {
//         return abs(sum1-sum2);
//     }
    
//     int p1 = partition(subset, index+1, sum1+subset[index], sum2);
    
//     int p2 = partition(subset, index+1, sum1, sum2+subset[index]);
    
//     return min(p1, p2);
// }

vector<vector<int>> memo;

// Top-down
int partition(vector<int>& subset, int index, int sum1, int sum2) {
    if(index == subset.size()) {
        return abs(sum1-sum2);
    }
    
    if(memo[index][sum1] == -1) {
        int p1 = partition(subset, index+1, sum1+subset[index], sum2);
        
        int p2 = partition(subset, index+1, sum1, sum2+subset[index]);
        
        memo[index][sum1] = min(p1, p2);
    }
    
    return memo[index][sum1];
}

int main() {
    vector<int> subset = {1, 2, 3, 4};
    int sum = 0;
    for(int s : subset) {
        sum += s;
    }
    memo.resize(subset.size(), vector<int>(sum+1, -1));
    cout << "Minimum Subset Sum Difference: " << partition(subset, 0, 0, 0);
    return 0;
}