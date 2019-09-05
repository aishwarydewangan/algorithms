/*

Given two strings ‘s1’ and ‘s2’, find the length of the longest substring which is common 
in both the strings.

Example 1:
    Input: s1 = "abdca"     s2 = "cbda"
    Output: 2
    Explanation: The longest common substring is "bd".

Example 2:
    Input: s1 = "passport"      s2 = "ppsspt"
    Output: 3
    Explanation: The longest common substring is "ssp".

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> memo;

// Top-down
int lcs(string& input1, string& input2, int index1, int index2, int count) {
    if(index1 == input1.size() or index2 == input2.size()) {
        return count;
    }
    
    if(memo[index1][index2][count] == -1) {
        
        int count1 = count;
        
        if(input1[index1] == input2[index2]) {
            count1 = lcs(input1, input2, index1+1, index2+1, count+1);
        }
        
        int count2 = lcs(input1, input2, index1+1, index2, 0);
        int count3 = lcs(input1, input2, index1, index2+1, 0);
        
        memo[index1][index2][count] = max(count1, max(count2, count3));
    }
    
    return memo[index1][index2][count];
}

// Bottom-up
int lcs(string& input1, string& input2) {
    
    int length = INT_MIN, n1 = input1.size(), n2 = input2.size();
    
    vector<vector<int>> dp(n1+1, vector<int>(n2+1));
    
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(input1[i] == input2[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
                length = max(length, dp[i][j]);
            }
        }
    }
    
    return length;
}

int main() {
    string input1 = "abdca", input2 = "cbda";
    int n1 = input1.size(), n2 = input2.size();
    memo.resize(n1, vector<vector<int>>(n2, vector<int>(max(n1, n2), -1)));
    cout << "Length of Longest Common Substring: " << lcs(input1, input2);
    return 0;
}