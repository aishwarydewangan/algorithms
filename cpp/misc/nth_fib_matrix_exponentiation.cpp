#include <bits/stdc++.h>

#define ll long long
#define matrix vector<vector<ll>>
#define MOD 1000000007

using namespace std;

matrix mul(const matrix& v1, const matrix& v2) {
    matrix res(2, vector<ll>(2, 1));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            res[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                res[i][j] = ((res[i][j]) % MOD + (v1[i][k]*v2[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}

matrix power(matrix& base, ll e) {
    matrix res(2, vector<ll>(2, 1));
    res[0][0] = 0;
    while(e > 0) {
        if(e%2 == 1)
            res = mul(base, res);
        base = mul(base, base);
        e = e/2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll int n;
        cin >> n;
        matrix fp(2, vector<ll>(1, 1));
        fp[0][0] = 0;
        fp[1][0] = 1;
        matrix fn(2, vector<ll>(1, 1));
        matrix t(2, vector<ll>(2, 1));
        t[0][0] = 0;
        t = power(t, n-1);
        fn[0][0] = t[0][0]*fp[0][0] + t[0][1]*fp[1][0];
        fn[1][0] = t[1][0]*fp[0][0] + t[1][1]*fp[1][0];
        cout << fn[0][0] << endl;
        
    }
    return 0;
}