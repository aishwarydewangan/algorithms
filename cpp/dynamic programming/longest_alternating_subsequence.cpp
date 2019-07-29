/*

Given a number sequence, find the length of its Longest Alternating Subsequence (LAS). A subsequence is 
considered alternating if its elements are in alternating order.

A three element sequence (a1, a2, a3) will be an alternating sequence if its elements hold one of the 
following conditions:   {a1 > a2 < a3 } or { a1 < a2 > a3}. 

Example 1:
    Input: {1,2,3,4}
    Output: 2
    Explanation: There are many LAS: {1,2}, {3,4}, {1,3}, {1,4}

Example 2:
    Input: {3,2,1,4}
    Output: 3
    Explanation: The LAS are {3,2,4} and {2,1,4}.

Example 3:
    Input: {1,3,2,4}
    Output: 4
    Explanation: The LAS is {1,3,2,4}.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> memo;

int las(vector<int>& nums, int pre, int curr, bool order) {
    if(curr == nums.size()) {
        return 0;
    }
    
    if(memo[pre+1][curr][order] != -1) {
        return memo[pre+1][curr][order];
    }
    
    int len1 = 0;
    
    if(order) {
        if(pre == -1 or nums[curr] > nums[pre])
            len1 = las(nums, curr, curr+1, !order)+1;
    } else {
        if(pre == -1 or nums[curr] < nums[pre])
            len1 = las(nums, curr, curr+1, !order)+1;
    }
    
    int len2 = las(nums, pre, curr+1, order);
    
    return (memo[pre+1][curr][order] = max(len1, len2));
}

int main() {
    vector<int> nums = {1,3,2,4};
    int n = nums.size();
    memo.resize(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
    cout << max(las(nums, -1, 0, true), las(nums, -1, 0, false));
    return 0;
}