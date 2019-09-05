/*

Given two strings ‘s1’ and ‘s2’, find the length of the longest subsequence which is common 
in both the strings.

A subsequence is a sequence that can be derived from another sequence by deleting some or no 
elements without changing the order of the remaining elements.

Example 1:
    Input: s1 = "abdca"         s2 = "cbda"
    Output: 3
    Explanation: The longest common subsequence is "bda".

Example 2:
    Input: s1 = "passport"      s2 = "ppsspt"
    Output: 5
    Explanation: The longest common subsequence is "psspt".

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

// Top-down
int lcs(string& input1, string& input2, int index1, int index2) {
    if(index1 == input1.size() or index2 == input2.size()) {
        return 0;
    }
    
    if(memo[index1][index2] != -1) {
        return memo[index1][index2];
    }
    
    if(input1[index1] == input2[index2]) {
        memo[index1][index2] = lcs(input1, input2, index1+1, index2+1)+1;
    } else {
        int count1 = lcs(input1, input2, index1+1, index2);
        
        int count2 = lcs(input1, input2, index1, index2+1);

        memo[index1][index2] = max(count1, count2);
    }
    
    return memo[index1][index2];
}

// Bottom-up
int lcs(string& input1, string& input2) {
    int n1 = input1.size(), n2 = input2.size();
    memo.clear();
    memo.resize(n1+1, vector<int>(n2+1, 0));
    int length = 0;
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(input1[i-1] == input2[j-1]) {
                memo[i][j] = memo[i-1][j-1]+1;
            } else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
            length = max(length, memo[i][j]);
        }
    }
    return length;
}

int main() {
    string input1 = "passport", input2 = "ppsspt";
    int n1 = input1.size(), n2 = input2.size();
    memo.resize(n1+1, vector<int>(n2+1, -1));
    cout << "Length of Longest Common Subsequence: " << lcs(input1, input2);
    return 0;
}