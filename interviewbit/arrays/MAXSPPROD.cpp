/*

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

1. LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j.

2. RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.

Input: You will receive array of integers as argument to function.

Return: Maximum special product of any integer in the array modulo 1000000007.

Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9
*/

#define ll long long
#define MOD 1000000007
 
int Solution::maxSpecialProduct(vector<int> &A) {
    ll n = A.size();
    stack<ll> left, right;
    left.push(0);
    right.push(n-1);
    vector<ll> L(n, 0), R(n, 0);
    for(ll i = 1; i < n; i++) {
        bool flag = true;
        while(!left.empty() && flag) {
            ll j = left.top();
            if(A[j] > A[i]) {
                L[i] = j;
                flag = false;
            } else {
                left.pop();
            }
        }
        left.push(i);
    }
    for(ll i = n-2; i >= 0; i--) {
        bool flag = true;
        while(!right.empty() && flag) {
            ll j = right.top();
            if(A[j] > A[i]) {
                R[i] = j;
                flag = false;
            } else {
                right.pop();
            }
        }
        right.push(i);
    }
    ll res = INT_MIN;
    for(ll i = 0; i < n; i++) {
        res = max(res, (L[i]*R[i]));
    }
    return res % MOD;
}