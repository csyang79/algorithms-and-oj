//超时，check改为使用unordered_map任然超时
class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<vector<string>> result;
			for (string& str : strs)
			{
				int i;
				for (i = 0; i < result.size(); ++i)
				{
					if (check(result[i][0], str))
					{
						result[i].push_back(str);
						break;
					}
				}
				if (i == result.size())
					result.push_back(vector<string>{str});
			}
			return result;
		}
		bool check(string str1, string str2)
		{
			if (str1.size() != str2.size())
				return false;
			sort(str1.begin(), str1.end());
			sort(str2.begin(), str2.end());
			return str1 == str2;
		}
};


class Solution {
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			unordered_map<string, int> mp;
			vector<vector<string>> result;
			string t;
			for (string str : strs)
			{
				t = str;
				sort(t.begin(), t.end());
				if (mp.find(t) == mp.end())
				{
					mp[t] = result.size();
					result.push_back(vector<string>{str});
				}
				else
					result[mp[t]].push_back(str);
			}
			return result;
		}
};
