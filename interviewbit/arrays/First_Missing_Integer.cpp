/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size(), j = 0;
    for(int i = 0; i < n; i++) {
        if(A[i] <= 0) {
            swap(A[i], A[j]);
            j++;
        }
    }
    A.erase(A.begin(), A.begin()+j);
    n = A.size();
    for(int i = 0; i < n; i++) {
        j = abs(A[i]);
        if(j-1 < n && A[j-1] > 0) {
            A[j-1] = -A[j-1];
        }
    }
    for(int i = 0; i < n; i++) {
        if(A[i] > 0) {
            return i+1;
        }
    }
    return n+1;
}