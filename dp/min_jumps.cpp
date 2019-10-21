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

// O(n^2)
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

// O(n)
int jumps(vector<int> &arr) {

    int n = arr.size(); 
      
    // The number of jumps needed to reach the starting index is 0 
    if (n <= 1) 
        return 0; 
  
    // Return -1 if not possible to jump 
    if (arr[0] == 0) 
        return -1; 
  
    // initialization 
    int maxReach = arr[0];  // stores all time the maximal reachable index in the array. 
    int step = arr[0];      // stores the number of steps we can still take 
    int jump =1;//stores the number of jumps necessary to reach that maximal reachable position. 
  
    // Start traversing array 
    int i=1; 
    for (i = 1; i < n; i++) 
    { 
        // Check if we have reached the end of the array 
        if (i == n-1) 
            return jump; 
  
        // updating maxReach 
        maxReach = max(maxReach, i+arr[i]); 
  
        // we use a step to get to the current index 
        step--; 
  
        // If no further steps left 
        if (step == 0) 
        { 
            // we must have used a jump 
            jump++; 
  
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if(i >= maxReach) 
                return -1; 
  
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
            step = maxReach - i; 
        } 
    } 
  
    return -1; 
}

int main() {
    vector<int> nums = {2,1,1,1,4};
    memo.resize(nums.size()+1, -1);
    cout << "Min Jumps: " << jumps(nums, 0);
    return 0;
}