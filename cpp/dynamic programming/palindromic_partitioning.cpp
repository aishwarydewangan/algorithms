#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> memo;

bool isPalindrome(string& input, int l, int r) {
    while(l <= r) {
        if(input[l] != input[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int minPartition(string& input, int l, int r) {
    if(l >= r or isPalindrome(input, l, r)) {
        return 0;
    }
    
    if(memo[l][r] != -1) {
        return memo[l][r];
    }
    
    int minCuts = r-l;
    for(int i = l; i <= r; i++) {
        if(isPalindrome(input, l, i)) {
            minCuts = min(minCuts, minPartition(input, i+1, r)+1);
        }
    }
    return (memo[l][r] = minCuts);
}

int main() {
    string input = "cddpd";
    int n = input.size();
    memo.resize(n, vector<int>(n, -1));
    cout << "Minimum number of cuts needed: " << minPartition(input, 0, n-1);
    return 0;
}