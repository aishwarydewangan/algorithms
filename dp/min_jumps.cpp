/*

Problem Statement
Given an array of positive numbers, where each element represents the max number of jumps that 
can be made forward from that element, write a program to find the minimum number of jumps needed 
to reach the end of the array (starting from the first element). If an element is 0, then we cannot 
move through that element.

Example 1:
    Input = {2,1,1,1,4}
    Output = 3
    Explanation: Starting from index '0', we can reach the last index through: 0->2->3->4

Example 2:
    Input = {1,1,3,6,9,3,0,1,3}
    Output = 4
    Explanation: Starting from index '0', we can reach the last index through: 0->1->2->3->8

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

int jumps(vector<int>& nums, int index) {
    if(index == nums.size()-1) {
        return 0;
    }
    
    if(nums[index] == 0) {
        return INT_MAX;
    }
    
    if(memo[index] != -1) {
        return memo[index];
    }
    
    int jump = INT_MAX;
    
    for(int i = 1; i <= nums[index]; i++) {
        if(index+i <= nums.size()-1) {
            int j = jumps(nums, index+i);
            if(j != INT_MAX) {
                jump = min(jump, j+1);
            }
        }
    }
    
    return (memo[index] = jump);
}

int main() {
    vector<int> nums = {2,1,1,1,4};
    memo.resize(nums.size()+1, -1);
    cout << "Min Jumps: " << jumps(nums, 0);
    return 0;
}