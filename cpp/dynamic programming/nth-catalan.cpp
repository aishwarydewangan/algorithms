/*

The Catalan numbers form a sequence of natural numbers that occur in various counting problems, often involving recursively-defined objects.

The first few catalan numbers from i = 0, 1, 2, 3, ... are 1, 1, 2, 5, ....

Given n, find nth catalan number.

*/

#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

vector<ull> memo;

ull catalan(ull n) {
    if(n <= 1) {
        return 1;
    }
    
    if(memo[n] != -1) {
        return memo[n];
    }
    
    ull res = 0;
    
    for(int i = 0; i < n; i++) {
        res += catalan(i)*catalan(n-i-1);
    }
    
    return (memo[n] = res);
}

int main() {
    ull n;
    cin >> n;
    memo.resize(n+1, -1);
    cout << catalan(n);
}