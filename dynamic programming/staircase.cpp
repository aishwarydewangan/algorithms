/*

Given a stair with ‘n’ steps, implement a method to count how many possible ways are there 
to reach the top of the staircase, given that, at every step you can either take 1 step, 2 steps, or 3 steps.

Example 1:
    Number of stairs (n) : 3
    Number of ways = 4
    Explanation: Following are the four ways we can climb : {1,1,1}, {1,2}, {2,1}, {3} 

Example 2:
    Number of stairs (n) : 4
    Number of ways = 7
    Explanation: Following are the seven ways we can climb : {1,1,1,1}, {1,1,2}, {1,2,1}, {2,1,1}, {2,2}, {1,3}, {3,1}

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> memo;

// Brute-force
int ways_bf(int n) {
    if(n == 0 or n == 1 or n == 2) {
        if(n == 0) {
            return 1;
        }
        return n;
    }
    
    int steps1 = ways_bf(n-1);
    int steps2 = ways_bf(n-2);
    int steps3 = ways_bf(n-3);
    
    return (steps1+steps2+steps3);
}

// Top-down
int ways_td(int n) {
    if(memo[n] == 0) {
        int steps1 = ways_td(n-1);
        int steps2 = ways_td(n-2);
        int steps3 = ways_td(n-3);
        
        memo[n] = steps1+steps2+steps3;
    }
    
    return memo[n];
}

// Bottom-up
int ways_bu(int n) {
    for(int i = 3; i <= n; i++) {
        memo[i] = memo[i-1]+memo[i-2]+memo[i-3];
    }
    return memo[n];
}

int main() {
    int n = 3;
    memo.resize(n+1, 0);
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    cout << "Ways to reach step " << n << ": " << ways_bu(n);
    return 0;
}