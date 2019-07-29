/*

Given a sequence, find the length of its longest repeating subsequence (LRS). A repeating subsequence 
will be the one that appears at least twice in the original sequence and is not overlapping (i.e. none 
of the corresponding characters in the repeating subsequences have the same index).

Example 1:
    Input: "tomorrow"
    Output: 2
    Explanation: The longest repeating subsequence is “or”.

Example 2:
    Input: "aabdbcec"
    Output: 3
    Explanation: The longest repeating subsequence is “abc”.

Example 3:
    Input: "fmff"
    Output: 2
    Explanation: The longest repeating subsequence is “ff”. Please note the second last character is shared 
                    in LRS.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int lrs(string& input, int i1, int i2) {
    if(i1 == input.size() or i2 == input.size()) {
        return 0;
    }
    
    if(memo[i1][i2] != -1) {
        return memo[i1][i2];
    }
    
    if(i1 != i2 and input[i1] == input[i2]) {
        return (memo[i1][i2] = (lrs(input, i1+1, i2+1)+1));
    }
    
    int len1 = lrs(input, i1+1, i2);
    int len2 = lrs(input, i1, i2+1);
    
    return (memo[i1][i2] = max(len1, len2));
}

int main() {
    string input = "aabdbcec";
    int n = input.size();
    memo.resize(n, vector<int>(n, -1));
    cout << "Length of Longest Repeating Subsequence: " << lrs(input, 0, 0);
    return 0;
}