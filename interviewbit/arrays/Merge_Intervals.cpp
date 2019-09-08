/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
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
 
vector<Interval> Solution::insert(vector<Interval> &A, Interval m) {
    vector<Interval> res(A.begin(), A.end());
    res.push_back(m);
    sort(res.begin(), res.end(), comp);
    int n = res.size();
    vector<Interval> ans;
    ans.push_back(res[0]);
    for(int i = 1; i < n; i++) {
        Interval obj = ans.back();
        if(obj.end < res[i].start) {
            ans.push_back(res[i]);
            continue;
        }
        ans.back().end = max(obj.end, res[i].end);
    }
    return ans;
}