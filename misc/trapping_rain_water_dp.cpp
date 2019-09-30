/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty())
		    return 0;
        int n = height.size();
        vector<int> left(n, 0), right(n, 0);
        left[0] = height[0];
        for(int i = 1; i < n; i++) {
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += (min(left[i], right[i])-height[i]);
        }
        return res;
    }
};