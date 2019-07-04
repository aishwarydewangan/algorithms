/*

Given a chain (A1, A2,..., An) of n matrices, where for i = 1, 2,...., n, matrix Ai has dimension p[i􏰐-1]xp[i],fully 
parenthesize the product A1, A2,...􏰏􏰏􏰏An in a way that minimizes the number of scalar multiplications.

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n+1, 0);
    for(int i = 0; i < n; i++) {
        cin >> p[i] >> p[i+1];
    }
    vector< vector<int> > m(n+1, vector<int>(n+1, 0));
    for(int d = 1; d < n; d++) {
        for(int i = 1; i <= n-d; i++) {
            int j = i+d;
            m[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                m[i][j] = min(m[i][j], m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << m[1][n];
}