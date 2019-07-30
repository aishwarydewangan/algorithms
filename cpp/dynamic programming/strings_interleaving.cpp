/*

Give three strings ‘m’, ‘n’, and ‘p’, write a method to find out if ‘p’ has been formed by 
interleaving ‘m’ and ‘n’. ‘p’ would be considered interleaving ‘m’ and ‘n’ if it contains all 
the letters from ‘m’ and ‘n’ and the order of letters is preserved too.

Example 1:
    Input: m="abd", n="cef", p="abcdef"
    Output: true
    Explanation: 'p' contains all the letters from 'm' and 'n' and preserves their order too. 

Example 2:
    Input: m="abd", n="cef", p="adcbef"
    Output: false
    Explanation: 'p' contains all the letters from 'm' and 'n' but does not preserve the order. 

Example 3:
    Input: m="abc", n="def", p="abdccf"
    Output: false
    Explanation: 'p' does not contain all the letters from 'm' and 'n'. 

Example 4:
    Input: m="abcdef", n="mnop", p="mnaobcdepf"
    Output: true
    Explanation: 'p' contains all the letters from 'm' and 'n' and preserves their order too.

*/

#include <bits/stdc++.h>

using namespace std;

map<tuple<int, int, int>, bool> mp;

bool interleave(string& m, string& n, string& p, int i1, int i2, int i3) {
    
    if(i1 == m.size() and i2 == n.size() and i3 == p.size()) {
        return true;
    }
    
    if(i3 == p.size()) {
        return false;
    }
    
    if(mp.find({i1, i2, i3}) != mp.end()) {
        return mp[{i1, i2, i3}];
    }
    
    bool b1 = false, b2 = false;
    
    if(i1 < m.size()) {
        if(m[i1] == p[i3]) {
            b1 = interleave(m, n, p, i1+1, i2, i3+1);
        }
    }
    
    if(i2 < n.size()) {
        if(n[i2] == p[i3]) {
            b2 = interleave(m, n, p, i1, i2+1, i3+1);
        }
    }
    
    return (mp[{i1, i2, i3}] = (b1 or b2));
}

int main() {
    string m = "abcdef", n = "mnop", p = "mnaobcdepf";
    cout << interleave(m, n, p, 0, 0, 0);
    return 0;
}