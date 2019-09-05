/*

Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

//My Solution: Hashing, sliding windows kind of, two pointers.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int mx = 1;
        int left = 0, right = 0;
        map<char, int> mp;
        mp[s[0]] = 0;
        while(right < s.size()) {
            if(left == right) {
                //cout << "\nLeft is equal to right.\tIncreasing right...";
                mp[s[right]] = right;
                right++;
            }
            if(right < s.size()) {
                if(mp.find(s[right]) != mp.end() && left <= mp[s[right]]) {
                    //cout << "\nDuplicate char found: " << s[right];
                    mx = max(mx, right-left);
                    left++;
                } else {
                    //cout << "\nJust increasing right...";
                    mp[s[right]] = right;
                    right++;
                }
            }
            //cout << "\nLeft: " << left << "\tRight: " << right << "\tMX: " << mx;
        }
        //cout << "\nLeft: " << left << "\tRight: " << right << "\tMX: " << mx;
        return max(mx, right-left);
    }
};

//Given Solution:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx = 0, i, j;
        map<char, int> mp;
        for(i = 0, j = 0; j < s.size(); j++) {
            if(mp.find(s[j]) != mp.end()) {
                i = max(mp[s[j]], i);
            }
            mx = max(mx, j-i+1);
            mp[s[j]] = j+1;
        }
        return mx;
    }
};