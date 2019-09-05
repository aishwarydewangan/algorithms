#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long

using namespace std;

void multiply(ll A[2][2], ll B[2][2]) {
    ll result[2][2] = {0};
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int k = 0; k < 2; k++)
                result[i][j] = (result[i][j] + (A[i][k] % MOD * B[k][j] % MOD) % MOD) % MOD;
    
    A[0][0] = result[0][0];
    A[0][1] = result[0][1];
    A[1][0] = result[1][0];
    A[1][1] = result[1][1];
}

void power(ll m[2][2], ll n) {
    if(n == 0 || n == 1)
        return;
    ll mat[2][2] = {{1, 1}, {1, 0}};
    power(m, n/2);
    multiply(m, m);
    if(n%2)
        multiply(m, mat);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll mat[2][2] = {{1, 1}, {1, 0}};
        power(mat, n-1);
        cout << mat[0][0] << endl;
    }
}