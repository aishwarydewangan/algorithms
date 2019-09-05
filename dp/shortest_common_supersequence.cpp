/*

Given two sequences ‘s1’ and ‘s2’, write a method to find the length of the shortest 
sequence which has ‘s1’ and ‘s2’ as subsequences.

Example 2:
    Input: s1: "abcf"       s2:"bdcf" 
    Output: 5
    Explanation: The shortest common super-sequence (SCS) is "abdcf". 

Example 2:
    Input: s1: "dynamic"    s2:"programming" 
    Output: 15
    Explanation: The SCS is "dynprogrammicng". 

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int lcs(string& input1, string& input2, int index1, int index2) {
    if(index1 == input1.size() or index2 == input2.size()) {
        return 0;
    }
    
    if(memo[index1][index2] != -1) {
        return memo[index1][index2];
    }
    
    int len1 = 0;
    
    if(input1[index1] == input2[index2]) {
        len1 = lcs(input1, input2, index1+1, index2+1)+1;
    }
    
    int len2 = lcs(input1, input2, index1+1, index2);
    int len3 = lcs(input1, input2, index1, index2+1);
    
    return (memo[index1][index2] = max(len1, max(len2, len3)));
}

int main() {
    string input1 = "abcd", input2 = "xycd";
    int n1 = input1.size(), n2 = input2.size();
    memo.resize(n1+1, vector<int>(n2+1, -1));
    int len = lcs(input1, input2, 0, 0);
    cout << "Length of Shortest Common Supersequence: " << n1+n2-len;
    return 0;
}