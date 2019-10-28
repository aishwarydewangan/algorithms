/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/

#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {
    int n = s.size();
    vector<bool> valid(n, false);
    stack<pair<char, int>> st;
    int i = 0;
    for(char c : s) {
        if(c == ')') {
            if(!st.empty()) {
                pair<char, int> p = st.top();
                if(p.first == '(') {
                    st.pop();
                    valid[i] = true;
                    valid[p.second] = true;
                }
            }
        } else {
            st.push(make_pair(c, i));
        }
        i++;
    }
    int count = INT_MIN, temp = 0;
    for(bool b : valid) {
        if(!b) {
            count = max(count, temp);
            temp = 0;
        } else {
            temp++;
        }
    }
    count = max(count, temp);
    return count;
}

int main() {
	string s = ")()())";
	cout << "\nLongest Valid Parentheses: " << longestValidParentheses(s);
	return 0;
}