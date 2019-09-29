/*
You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 
*/

int Solution::repeatedNumber(const vector<int> &nums) {
    int n = nums.size();
    if(n == 1) {
        return nums[0];
    }
    if(n == 2) {
        if(nums[0] == nums[1]) {
            return nums[0];
        }
        return -1;
    }
    int maj1 = INT_MAX, maj2 = INT_MAX, count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++) {
        if(maj1 == nums[i]) {
            count1 += 1;
        } else if(maj2 == nums[i]) {
            count2 += 1;
        } else if(count1 == 0) {
            maj1 = nums[i];
            count1 = 1;
        } else if(count2 == 0) {
            maj2 = nums[i];
            count2 = 1;
        } else {
            count1 -= 1;
            count2 -= 1;
        }
    }
    count1 = count2 = 0;
    for(int i = 0; i < n; i++) {
        if(maj1 == nums[i]) {
            count1++;
        } else if(maj2 == nums[i]) {
            count2++;
        }
    }
    if(count1 > n/3) {
        return maj1;
    }
    if(count2 > n/3) {
        return maj2;
    }
    return -1;
}