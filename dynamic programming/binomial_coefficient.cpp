#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

vector< vector<ull> > memo;

ull binomial(ull n, ull k) {
    if(k == 0 or n == k) {
        return 1;
    }
    
    if(memo[n][k] != -1) {
        return memo[n][k];
    }
    
    return (memo[n][k] = (binomial(n-1, k-1) + binomial(n-1, k)));
}

int main() {
    ull n, k;
    cin >> n >> k;
    memo.resize(n+1, vector<ull>(k+1, -1));
    cout << binomial(n, k);
}