/*

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

	Input: candidates = [2,3,6,7], target = 7
	Output: [[2,2,3],[7]]

	Explanation: 
		2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
		7 is a candidate, and 7 = 7.
		These are the only two combinations.

Example 2:

	Input: candidates = [2,3,5], target = 8
	Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:

	Input: candidates = [2], target = 1
	Output: []

Example 4:

	Input: candidates = [1], target = 1
	Output: [[1]]

Example 5:

	Input: candidates = [1], target = 2
	Output: [[1,1]]
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> res;
    
void dfs(vector<int>& nums, int i, int target, vector<int> &sub) {
    if(target == 0) {
        res.push_back(sub);
        return;
    }
    
    if(i >= nums.size()) {
        return;
    }
    
    if(target-nums[i] >= 0) {
        sub.push_back(nums[i]);
        dfs(nums, i, target-nums[i], sub);
        sub.pop_back();
    }
    
    
    dfs(nums, i+1, target, sub);
}

void combinationSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> sub;
    
    dfs(nums, 0, target, sub);
}

int main() {
	vector<int> candidates = {2,3,6,7};
	int target = 7;

	combinationSum(candidates, target);

	for(int i = 0; i < res.size(); i++) {
		cout << "\nCombination " << i+1 << ": ";
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
	}
	return 0;
}