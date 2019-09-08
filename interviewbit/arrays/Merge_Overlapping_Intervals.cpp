/*

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 static bool comp(const Interval a, const Interval b) {
     if(a.start == b.start) {
         return a.end < b.end;
     }
     return a.start < b.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> res;
    int n = A.size();
    if(n == 0) {
        return res;
    }
    sort(A.begin(), A.end(), comp);
    res.push_back(A[0]);
    for(int i = 1; i < n; i++) {
        Interval obj = res.back();
        if(obj.end < A[i].start) {
            res.push_back(A[i]);
            continue;
        }
        res.back().end = max(obj.end, A[i].end);
    }
    return res;
}