/*

Given a string, find the length of its Longest Palindromic Substring (LPS). In a palindromic 
string, elements read the same backward and forward.

Example 1:
    Input: "abdbca"
    Output: 3
    Explanation: LPS is "bdb".

Example 2:
    Input: = "cddpd"
    Output: 3
    Explanation: LPS is "dpd".

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
    
    if(input[l] == input[r]) {
        
        int length = r-l-1;
        
        if(length == lps(input, l+1, r-1)) {
            return (memo[l][r] = length+2);
        }
    }
    return (memo[l][r] = max(lps(input, l, r-1), lps(input, l+1, r)));
}


int main() {
    string input = "abdbca";
    int n = input.size();
    memo.resize(n, vector<int>(n, -1));
    cout << "Length of Longest Palindromic Substring: " << lps(input, 0, n-1);
    return 0;
}