/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

static bool comp(const string a, const string b) {
    return ((a+b)>(b+a));
}
 
string Solution::largestNumber(const vector<int> &A) {
    int n = A.size();
    vector<string> res(n);
    for(int i = 0; i < n; i++) {
        res[i] = to_string(A[i]);
    }
    sort(res.begin(), res.end(), comp);
    if(res[0] == "0") {
        return "0";
    }
    string ans = "";
    for(int i = 0; i < n; i++) {
        ans += res[i];
    }
    return ans;
}