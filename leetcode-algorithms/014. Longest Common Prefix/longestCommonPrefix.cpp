//conner case
class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			if (strs.empty())
				return "";
			if (strs.size() == 1)
				return strs[0];
			int sz = INT_MAX;
			for (int i = 0; i < strs.size(); ++i)
				sz = std::min(sz, (int)strs[i].size());

			int r = 0;
			for (int i = 0, j; i < sz; ++i)
			{
				for (j = 1; j < strs.size() && strs[j][i] == strs[j - 1][i]; ++j);
				if (j != strs.size())
					return strs[0].substr(0, i);
			}
			return strs[0].substr(0, sz);
		}
};
