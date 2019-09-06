/*

Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the 
maximum length of s is 1000.

Example 1:
    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.

Example 2:
    Input: "cbbd"
    Output: "bb"
*/

class Solution {
public:
    int expandAroundCenter(string& s, int left, int right) {
        int L = left, R = right;
        while(L >= 0 && R < s.size() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R-L-1;
    }
    
    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int n = s.size();
        int start = 0, end = 0, len, mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            len = max(len1, len2);
            mx = max(mx, len);
            if(len > end-start) {
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(start, mx);
    }
};