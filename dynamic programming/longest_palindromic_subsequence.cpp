/*

Given a sequence, find the length of its Longest Palindromic Subsequence (LPS). In a palindromic 
subsequence, elements read the same backward and forward.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements 
without changing the order of the remaining elements.

Example 1:
    Input: "abdbca"
    Output: 5
    Explanation: LPS is "abdba".

Example 2:
    Input: = "cddpd"
    Output: 3
    Explanation: LPS is "ddd".

Example 3:
    Input: = "pqr"
    Output: 1
    Explanation: LPS could be "p", "q" or "r".

*/


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int lps(string& input, int l, int r) {
    if(l > r) {
        return 0;
    }
    
    if(l == r) {
        return 1;
    }
    
    if(memo[l][r] != -1) {
        return memo[l][r];
    }
    
    if(input[l] != input[r]) {
        return (memo[l][r] = max(lps(input, l+1, r), lps(input, l, r-1)));
    }
    
    return (memo[l][r] = lps(input, l+1, r-1)+2);
}

int main() {
    string input = "abdbca";
    int n = input.size();
    memo.resize(n, vector<int>(n, -1));
    cout << "Length of Longest Palindromic Subsequence: " << lps(input, 0, n-1);
    return 0;
}