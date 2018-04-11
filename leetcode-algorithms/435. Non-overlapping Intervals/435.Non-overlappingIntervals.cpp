/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b)\
             { return a.end < b.end; });
        int res = 1, end = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i].start >= end)
            {
                ++res; 
                end = intervals[i].end;
            }
        }
        return intervals.size()  - res;
    }
};
