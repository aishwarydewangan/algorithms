#include <bits/stdc++.h>

using namespace std;

int process(vector<int>& nums) {
	int max_so_far = nums[0], curr_max = nums[0];
	for(int i = 1; i < nums.size(); i++) {
		curr_max = max(nums[i], curr_max+nums[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

int main() {
	vector<int> nums = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout << process(nums);
	return 0;
}