/*

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/

#define ll long long
 
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    ll n = A.size();
    vector<int> res(2);
    ll N, S = 0, SqN, Sq = 0;
    if(n%2) {
        N = ((n+1)/2)*n;
    } else {
        N = (n/2)*(n+1);
    }
    SqN = ((n)*(n+1)*(2*n+1))/6;
    for(int i = 0; i < n; i++) {
        S += A[i];
        Sq += ((ll) A[i]) * ((ll) A[i]);
    }
    int x, y;
    y = (((Sq-SqN)/(S-N)) + (N-S))/2;
    x = S-N+y;
    return {x, y};
}