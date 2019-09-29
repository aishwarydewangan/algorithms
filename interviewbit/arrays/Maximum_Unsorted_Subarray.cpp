/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :
    Input 1:    A = [1, 3, 2, 4, 5]
    Return: [1, 2]

    Input 2:    A = [1, 2, 3, 4, 5]
    Return: [-1]

In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.
*/

vector<int> Solution::subUnsort(vector<int> &A) {
    int l = -1, r = -1, t = A[0], n = A.size();
    for(int i = 1; i < n; i++) {
        if(A[i] < t) {
            r = i;
        }
        t = max(t, A[i]);
    }
    t = A[n-1];
    for(int i = n-2; i >= 0; i--) {
        if(t < A[i]) {
            l = i;
        }
        t = min(t, A[i]);
    }
    if(l == -1) {
        return {-1};
    }
    return {l, r};
}