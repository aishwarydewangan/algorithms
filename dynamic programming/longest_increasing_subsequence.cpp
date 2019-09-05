/*

Given a number sequence, find the length of its Longest Increasing Subsequence (LIS). In an 
increasing subsequence, all the elements are in increasing order (from lowest to highest).

Example 1:
    Input: {4,2,3,6,10,1,12}
    Output: 5
    Explanation: The LIS is {2,3,6,10,12}.

Example 1:
    Input: {-4,10,3,7,15}
    Output: 4
    Explanation: The LIS is {-4,3,7,15}.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

// Top-down
int lis(vector<int>& nums, int pre, int curr) {
    if(curr >= nums.size()) {
        return 0;
    }
    
    if(memo[pre+1][curr] != -1) {
        return memo[pre+1][curr];
    }
    
    int len1 = 0;
    
    if(pre == -1 or nums[curr] > nums[pre]) {
        len1 = lis(nums, curr, curr+1)+1;
    }
    
    int len2 = lis(nums, pre, curr+1);
    
    return (memo[pre+1][curr] = max(len1, len2));
}

// Bottom-up
int lis(vector<int>& nums) {
    int n = nums.size();
    int len = 1;
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++) {
        int j = i-1;
        while(j >= 0) {
            if(nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j]+1);
                len = max(len, dp[i]);
            }
            j--;
        }
    }
    return len;
}

int main() {
    vector<int> nums = {4,10,4,3,8,9};
    int n = nums.size();
    memo.resize(n+1, vector<int>(n+1, -1));
    cout << "Length of Longest Increasing Subsequence: " << lis(nums);
    return 0;
}