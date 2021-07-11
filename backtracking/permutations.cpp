/*

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

	Input: nums = [1,2,3]
	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

	Input: nums = [0,1]
	Output: [[0,1],[1,0]]

Example 3:

	Input: nums = [1]
	Output: [[1]]
*/

#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > permutations;
    
void dfs(vector<int>& nums, int pos) {
    if(pos == nums.size()-1) {
        permutations.push_back(nums);
        return;
    }
    for(int i = pos; i < nums.size(); i++) {
        swap(nums[pos], nums[i]);
        dfs(nums, pos+1);
        swap(nums[pos], nums[i]);
    }
}

void permute(vector<int>& nums) {
    if(nums.size() != 0) {
        dfs(nums, 0);
    }
}

int main() {
	vector<int> nums = {1, 2, 3};
	permute(nums);
	for(auto vec : permutations) {
		for(auto v : vec) {
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}