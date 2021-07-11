/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

	Input: candidates = [10,1,2,7,6,1,5], target = 8
	Output: 
	[
	[1,1,6],
	[1,2,5],
	[1,7],
	[2,6]
	]

Example 2:

	Input: candidates = [2,5,2,1,2], target = 5
	Output: 
	[
	[1,2,2],
	[5]
	]
*/

#include <bits/stdc++.h>

using namespace std;

set<vector<int>> subs;

vector<vector<int>> res;
    
void dfs(vector<int>& nums, int i, int target, vector<int> &sub) {
    if(target == 0) {
        subs.insert(sub);
        return;
    }

    if(i >= nums.size()) {
        return;
    }

    if(target-nums[i] >= 0) {
        sub.push_back(nums[i]);
        dfs(nums, i+1, target-nums[i], sub);
        sub.pop_back();
    }


    dfs(nums, i+1, target, sub);
}

void combinationSum2(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> sub;

    dfs(nums, 0, target, sub);
    
    for(auto v: subs) {
        res.push_back(v);
    }
}

int main() {
	vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;

	combinationSum2(candidates, target);

	for(int i = 0; i < res.size(); i++) {
		cout << "\nCombination " << i+1 << ": ";
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
	}
	return 0;
}