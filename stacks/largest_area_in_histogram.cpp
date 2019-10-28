/*

Given n non-negative integers representing the histogram's bar height where the width 
of each bar is 1, find the area of largest rectangle in the histogram.

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/

#include <bits/stdc++.h>

using namespace std;

int largestArea(vector<int>& A) {
    int res = 0, area = 0, i = 0, n = A.size(), tp;
    stack<int> st;
    while(i < n) {
        if(st.empty() || A[st.top()] <= A[i]) {
            st.push(i++);
        } else {
            tp = st.top();
            st.pop();
            area = A[tp] * (st.empty() ? i : i-st.top()-1);
            res = max(res, area);
        }
    }
    while(not st.empty()) {
        tp = st.top();
        st.pop();
        area = A[tp] * (st.empty() ? i : i-st.top()-1);
        res = max(res, area);
    }
    return res;
}

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    cout << "\nLargest Area in Histogram: " << largestArea(nums);
    return 0;
}