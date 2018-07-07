//类似于有序数组去重, sort(n log n), merge(n)，总共O(nlogn)，注意sort比较函数的写法，须为static
class Solution {
	public:
		static bool compare(Interval a, Interval b)
		{
			return a.start < b.start || a.start == b.start && a.end < b.end;
		}
		vector<Interval> merge(vector<Interval>& intervals) {
			if (intervals.empty())
				return {};
			sort(intervals.begin(), intervals.end(), compare);
			int j = 0;
			for (int i = 1; i < intervals.size(); ++i)
			{
				if (intervals[i].start > intervals[j].end)
					intervals[++j] = intervals[i];
				else if (intervals[i].end <= intervals[j].end)
					continue;
				else
					intervals[j].end = intervals[i].end;
			}
			intervals.resize(++j);
			return intervals;
		}
};
