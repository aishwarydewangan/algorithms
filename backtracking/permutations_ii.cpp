/*

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

	Input: nums = [1,1,2]
	Output:
	[[1,1,2],
	 [1,2,1],
	 [2,1,1]]

Example 2:

	Input: nums = [1,2,3]
	Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > permutations;
    
void dfs(vector<int> nums, int pos) {
    if(pos == nums.size()-1) {
        permutations.push_back(nums);
        return;
    }
    for(int i = pos; i < nums.size(); i++) {
        if(i != pos && nums[i] == nums[pos]) {
            continue;
        }
        swap(nums[pos], nums[i]);
        dfs(nums, pos+1);
    }
}

void permuteUnique(vector<int>& nums) {
    if(nums.size()) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
    }
}

int main() {
	vector<int> nums = {1, 1, 2};
	permuteUnique(nums);
	for(auto vec : permutations) {
		for(auto v : vec) {
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}