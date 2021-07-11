/*

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

#include <bits/stdc++.h>

using namespace std;

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high) {
        while(low < high && nums[low] == nums[low+1])
            low++;
        
        while(low < high && nums[high-1] == nums[high])
            high--;
        
        int mid = low + (high-low)/2;

        if(target == nums[mid]) {
            return true;
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
    return false;
}

int main() {
	vector<int> nums = {2,5,6,0,0,1,2};
	int target = 0;
	cout << search(nums, target);
	return 0;
}