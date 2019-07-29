/*

Given a number sequence, find the length of its Longest Bitonic Subsequence (LBS). A subsequence is 
considered bitonic if it is monotonically increasing and then monotonically decreasing.

Example 1:
    Input: {4,2,3,6,10,1,12}
    Output: 5
    Explanation: The LBS is {2,3,6,10,1}.

Example 2:
    Input: {4,2,5,9,7,6,10,3,1}
    Output: 7
    Explanation: The LBS is {4,5,9,7,6,3,1}.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo, memoRev;

int lds(vector<int>& nums, int pre, int curr) {
    if(curr == nums.size()) {
        return 0;
    }
    
    if(memo[pre+1][curr] != -1) {
        return memo[pre+1][curr];
    }
    
    int len1 = 0;
    
    if(pre == -1 or nums[curr] < nums[pre]) {
        len1 = lds(nums, curr, curr+1)+1;
    }
    
    int len2 = lds(nums, pre, curr+1);
    
    return (memo[pre+1][curr] = max(len1, len2));
}

int ldsRev(vector<int>& nums, int pre, int curr) {
    if(curr < 0) {
        return 0;
    }
    
    if(memoRev[pre+1][curr] != -1) {
        return memoRev[pre+1][curr];
    }
    
    int len1 = 0;
    
    if(pre == -1 or nums[curr] < nums[pre]) {
        len1 = ldsRev(nums, curr, curr-1)+1;
    }
    
    int len2 = ldsRev(nums, pre, curr-1);
    
    return (memoRev[pre+1][curr] = max(len1, len2));
}

int lbs(vector<int>& nums) {
    int length = INT_MIN;
    for(int i = 0; i < nums.size(); i++) {
        int c1 = lds(nums, -1, i);
        int c2 = ldsRev(nums, -1, i);
        length = max(length, c1+c2-1);
    }
    return length;
}

int main() {
    vector<int> nums = {4,2,5,9,7,6,10,3,1};
    int n = nums.size();
    memo.resize(n+1, vector<int>(n+1, -1));
    memoRev.resize(n+1, vector<int>(n+1, -1));
    cout << "Length of Longest Bitonic Subsequence: " << lbs(nums);
    return 0;
}