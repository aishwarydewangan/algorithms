/*

A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
*/

//Solution 1
class Solution {
public:
    
    vector<vector<vector<int>>> memo;
    
    int wiggle(vector<int>& nums, int pre, int curr, bool order) {
        if(curr == nums.size()) {
            return 0;
        }
        
        if(memo[pre+1][curr][order] != -1) {
            return memo[pre+1][curr][order];
        }
        
        int w1 = 0;
        
        if(order) {
            if(pre == -1 or nums[curr]-nums[pre] < 0) {
                w1 = wiggle(nums, curr, curr+1, !order)+1;
            }
            
        } else {
            if(pre == -1 or nums[curr]-nums[pre] > 0) {
                w1 = wiggle(nums, curr, curr+1, !order)+1;
            }
        }
        
        int w2 = wiggle(nums, pre, curr+1, order);
        
        return (memo[pre+1][curr][order] = max(w1, w2));
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        memo.resize(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return max(wiggle(nums, -1, 0, true), wiggle(nums, -1, 0, false));
    }
};

//Solution 2
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        vector<vector<int>> dp(nums.size(),vector<int>(2,1));
        int m=0;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]!=nums[j]){
                    if(nums[i]>nums[j]){
                        dp[i][0]=max(dp[i][0],dp[j][1]+1);
                    }else{
                        dp[i][1]=max(dp[i][1],dp[j][0]+1);
                    }
                }
            }
            m=max(max(dp[i][0],dp[i][1]),m);
        }
        return m;
    }
};