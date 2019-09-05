#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

// Brute-force
int fib_bf(int n) {
    if(n < 2) {
        return n;
    }
    
    int fib1 = fib_bf(n-1);
    int fib2 = fib_bf(n-2);
    
    return (fib1+fib2);
}

// Top-down
int fib_td(int n) {
    if(n < 2) {
        return n;
    }
    
    if(memo[n] == -1) {
        int fib1 = fib_td(n-1);
        int fib2 = fib_td(n-2);
        
        memo[n] = fib1+fib2;
    }
    
    return memo[n];
}

// Bottom-up
int fib_bu(int n) {
    for(int i = 2; i <= n; i++) {
        memo[i] = memo[i-1]+memo[i-2];
    }
    return memo[n];
}

// Bottom-up Optimized
int fib_buo(int n) {
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = a+b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n = 4;
    memo.resize(n+1, -1);
    memo[0] = 0;
    memo[1] = 1;
    cout << "Fib(" << n << "): " << fib_buo(n);
    return 0;
}