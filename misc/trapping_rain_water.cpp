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
        int left = 0, right = n-1;
        int left_max = 0, right_max = 0, res = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                if(height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    res += left_max-height[left];
                }
                left += 1;
            } else {
                if(height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    res += right_max-height[right];
                }
                right -= 1;
            }
        }
        return res;
    }
};