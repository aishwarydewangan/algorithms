/*

Given a string and a pattern, write a method to count the number of times the pattern appears 
in the string as a subsequence.

Example 1: 
    Input: string: “baxmx”, patten: "ax"
    Output: 2
    Explanation: {baxmx, baxmx}.

Example 2:
    Input: string: “tomorrow”, pattern: "tor"
    Output: 4
    Explanation: Following are the four occurences: {tomorrow, tomorrow, tomorrow, tomorrow}.

*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

int patternCount(string& input, string& pattern, int i, int p) {
    if(p == pattern.size()) {
        return 1;
    }
    if(i == input.size()) {
        return 0;
    }
    if(memo[i][p] != -1) {
        return memo[i][p];
    }
    int count1 = 0;
    if(input[i] == pattern[p]) {
        count1 = patternCount(input, pattern, i+1, p+1);
    }
    int count2 = patternCount(input, pattern, i+1, p);
    return (memo[i][p] = count1+count2);
}

int main() {
    string input = "baxmx", pattern = "ax";
    int n = input.size(), p = pattern.size();
    memo.resize(n, vector<int>(p, -1));
    cout << "Number of times the pattern appears in the string: " << patternCount(input, pattern, 0, 0);
    return 0;
}