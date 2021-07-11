/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

	Input: n = 3
	Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

	Input: n = 1
	Output: ["()"]

*/

#include <bits/stdc++.h>

using namespace std;

vector<string> res;
string o = "(", c=")";
int len;

void dfs(string s, int a, int b) {
    if(a == len) {
        while(b < len) {
            s += c;
            b++;
        }
        res.push_back(s);
        return;
    }
    if(a < b || b == len) {
        return;
    }
    
    dfs(s+o, a+1, b);
    dfs(s+c, a, b+1); 
}

void generateParenthesis(int n) {
    len = n;
    dfs(o, 1, 0);
}

int main() {
	int n = 3;
	generateParenthesis(n);
	for(auto s : res) {
		cout << s << endl;
	}
	return 0;
}