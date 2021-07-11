/*

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        
        if(target == nums[mid]) {
            return mid;
        }
        
        if(nums[low] <= nums[mid]) {
            if(target < nums[mid] && target >= nums[low]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        } else {
            if(target > nums[mid] && target <= nums[high]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;
	cout << search(nums, target);
	return 0;
}