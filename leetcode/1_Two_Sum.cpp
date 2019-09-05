/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
	Given nums = [2, 7, 11, 15], target = 9,
	Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target-nums[i]) != mp.end() && mp[target-nums[i]] != i) {
                res.push_back(mp[target-nums[i]]);
                res.push_back(i);
                sort(res.begin(), res.end());
                return res;
            }
            mp[nums[i]] = i;
        }
        return res;
    }
};