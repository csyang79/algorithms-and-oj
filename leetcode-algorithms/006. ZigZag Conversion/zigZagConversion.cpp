class Solution {
	public:
		string convert(string s, int numRows) {
			if (numRows == 1)
				return s;
			vector<string> strs(numRows);
			int step = 0;
			bool flag = 0;
			for (char c : s)
			{
				strs[step].push_back(c);

				if (step == numRows - 1 || step == 0)
					flag = !flag;
				if (flag)
					++step;
				else
					--step;
			}
			string result;
			for (string str : strs)
				result += str;
			return result;
		}
};
