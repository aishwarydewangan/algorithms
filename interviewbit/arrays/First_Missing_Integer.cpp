/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

int Solution::firstMissingPositive(vector<int> &A) {
    // vector<int> v(A.size());
    int i,pos,n=A.size();
    for(i=0;i<n;i++){
        if(A[i]>0 && A[i]<=n){
            pos=A[i]-1;
            if(A[i]!=A[pos]){
                swap(A[i],A[pos]);
                i--;
            }
        }
    }
    for(i=0;i<n;i++){
        if(A[i]!=i+1)return i+1;
    }
    return A.size()+1;
}

