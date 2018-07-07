//注意边界条件,右边有空格，全空格，无空格，正常
class Solution {
	public:
		int lengthOfLastWord(string s) {
			if (s.empty())
				return 0;
			int begin, end;
			for (end = s.size() - 1; end >= 0 && s[end] == ' '; --end);
			if (end < 0)
				return 0;
			for (begin = end - 1; begin >= 0 && s[begin] != ' '; --begin);
			return end - begin;
		}
};
