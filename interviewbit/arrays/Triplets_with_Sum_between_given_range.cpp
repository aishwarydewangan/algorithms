/*
Given an array of real numbers greater than zero in form of strings.
Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
*/

int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<double> nums(n);
    for(int i = 0; i < A.size(); i++) {
        nums[i] = stod(A[i]);
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = n-1;
    while(l < r-1) {
        double sum = nums[l]+nums[l+1]+nums[r];
        if(sum > 1 && sum < 2) {
            return 1;
        }
        if(sum <= 1) {
            l++;
        }
        if(sum >= 2) {
            r--;
        }
    }
    return 0;
}