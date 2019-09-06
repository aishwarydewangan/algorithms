/*

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) {
            return "";
        }
        if(strs.size() == 1) {
            return strs[0];
        }
        string ans = "";
        int i = 0;
        bool loop = true;
        string first = strs[0];
        while(loop) {
            if(i > first.size()) {
                loop = false;
            } else {
                for(int j = 1; j < strs.size() && loop; j++) {
                    if(i > strs[j].size()) {
                        loop = false;
                    } else {
                        if(first[i] != strs[j][i])
                            loop = false;
                    }
                }
                if(loop) {
                    ans += first[i];
                }
            }
            i++;
        }
        return ans;
    }
};