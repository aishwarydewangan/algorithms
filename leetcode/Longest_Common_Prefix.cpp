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

*/

/*

Solution 1: 

    Intuition: LCP(S1, S2, S3, ......, Sn) = LCP(LCP(LCP(S1, S2), S3), ...., Sn)

    Time Complexity: O(S), S = sum of all characters in all strings

    Space Complexity: O(1)

Solution 2: Vertical Scanning

    Thought of this solution.

    Intuition: Starting from index 0 scan each index of all strings till minLength (length of shortest string)

    Time Complexity: Let n = no. of strings
        Worst Case: All strings have same length m, then = O(m.n)
        Best Case: O(n.minLength)

    Space Complexity: O(1)

Solution 3: Divide and Conquer

    Intuition: LCP(S1, S2, S3, ......, Sn) = LCP(LCP(S1, S2, ...., Sk), LCP(Sk+1, Sk+2, ....., Sn))
*/

//My Solution: Vertical Scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0 || strs.size() == 1) {
            return (strs.size() ? strs[0] : "");
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
                        if(first[i] != strs[j][i]) {
                            loop = false;
                        }
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