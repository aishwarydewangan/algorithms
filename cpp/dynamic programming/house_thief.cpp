/*

There are ‘n’ houses built in a line. A thief wants to steal maximum possible money from 
these houses. The only restriction the thief has is that he can’t steal from two consecutive 
houses, as that would alert the security system. How should the thief maximize his stealing?

Given a number array representing the wealth of ‘n’ houses, determine the maximum amount of money 
the thief can steal without alerting the security system.

Example 1:
    Input: {2, 5, 1, 3, 6, 2, 4}
    Output: 15
    Explanation: The thief should steal from houses 5 + 6 + 4

Example 2:
    Input: {2, 10, 14, 8, 1}
    Output: 18
    Explanation: The thief should steal from houses 10 + 8

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int rob(vector<int>& nums, int index) {
    if(index >= nums.size()) {
        return 0;
    }
    
    if(memo[index] != -1) {
        return memo[index];
    }
    
    int r1 = rob(nums, index+1);
    int r2 = rob(nums, index+2) + nums[index];
    
    return (memo[index] = max(r1, r2));
}

int main() {
    vector<int> nums = {2, 5, 1, 3, 6, 2, 4};
    memo.resize(nums.size()+1, -1);
    cout << "\nMax Amount: " << rob(nums, 0);
    return 0;
}