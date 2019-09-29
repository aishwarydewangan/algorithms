/*
Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].

If there is no solution possible, return -1.

Example :
    A : [3 5 4 2]

    Output : 2, for the pair (3, 4)
*/

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<int> left(n), right(n);
    left[0] = A[0];
    right[n-1] = A[n-1];
    for(int i = 1; i < n; i++) {
        left[i] = min(left[i-1], A[i]);
    }
    for(int i = n-2; i >= 0; i--) {
        right[i] = max(right[i+1], A[i]);
    }
    int i = 0, j = 0, diff = -1;
    while(i < n && j < n) {
        if(left[i] <= right[j]) {
            diff = max(diff, j-i);
            j++;
        } else {
            i++;
        }
    }
    return diff;
}