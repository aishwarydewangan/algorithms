/*

Given a number sequence, find the increasing subsequence with the highest sum. Write a method 
that returns the highest sum.

Example 1:
    Input: {4,1,2,6,10,1,12}
    Output: 32
    Explanation: The increaseing sequence is {4,6,10,12}. 
    Please note the difference, as the LIS is {1,2,6,10,12} which has a sum of '31'.

Example 2:
    Input: {-4,10,3,7,15}
    Output: 25
    Explanation: The increaseing sequences are {10, 15} and {3,7,15}.

*/


#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;

int maxLIS(vector<int>& nums, int pre, int curr, int sum) {
    if(curr == nums.size()) {
        return sum;
    }
    
    string key = to_string(curr) + "/" + to_string(pre) + "/" + to_string(sum);
    
    if(mp.find(key) != mp.end()) {
        return mp[key];
    }
    
    int sum1 = 0;
    
    if(pre == -1 or nums[curr] > nums[pre]) {
        sum1 = maxLIS(nums, curr, curr+1, sum+nums[curr]);
    }
    
    int sum2 = maxLIS(nums, pre, curr+1, sum);
    
    return (mp[key] = max(sum1, sum2));
}

int main() {
    vector<int> nums = {-4,10,3,7,15};
    cout << "Maximum Sum of Increasing Subsequence: " << maxLIS(nums, -1, 0, 0);
    return 0;
}