/*

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.


Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 2) {
            return min(height[0], height[1]);
        }
        int h, w, a = 1;
        for(int i = 0, j = n-1; i != j;) {
            h = min(height[i], height[j]);
            w = j-i;
            a = max(a, h*w);
            if(i+1 == j) {
                break;
            }
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return a;
    }
};