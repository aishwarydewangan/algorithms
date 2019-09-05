/*

You are given an array of N integers, A1, A2 ,…, AN. Return maximum 
value of f(i, j) for all 1 ≤ i, j ≤ N. 

f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/

int Solution::maxArr(vector<int> &A) {
    int res = INT_MIN, pmax = INT_MIN, pmin = INT_MAX, nmax = INT_MIN, nmin = INT_MAX;
    for(int i = 0; i < A.size(); i++) {
        int a = A[i]+i, b = A[i]-i;
        pmax = max(pmax, a);
        pmin = min(pmin, a);
        nmax = max(nmax, b);
        nmin = min(nmin, b);
    }
    return max(pmax-pmin, nmax-nmin);
}