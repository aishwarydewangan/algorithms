/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        string ans = "";
        vector<string> res(numRows);
        int r = 0, i = 0;
        bool dir = true;
        while(i < s.size()) {
            if(dir) {
                res[r].push_back(s[i]);
                r++;
                if(r == numRows-1) {
                    dir = false;
                }
            } else {
                res[r].push_back(s[i]);
                r--;
                if(r == 0) {
                    dir = true;
                }
            }
            i++;
        }
        for(i = 0; i < numRows; i++) {
            ans += res[i];
        }
        return ans;
    }
};