/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :
    Input : [1, 10, 5]
    Output : 5 

Return 0 if the array contains less than 2 elements.

1. You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
2. You may also assume that the difference will not overflow.
*/

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2) return 0;
    vector<int> B = A;
    sort(B.begin(),B.end());
    int res = 0;
    for(int i=0;i<B.size()-1;i++) {
        res = max(res, B[i+1]-B[i]);
    }
    return res;
}