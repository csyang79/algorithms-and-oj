//暴力beat 100%, ijk分别为234字段开始位置
//note:IP合法判断(0开头)或0本身
class Solution {
	public:
		vector<string> restoreIpAddresses(string s) {
			vector<string> res;
			const int n = s.size();
			for (int i = 1; i < 4; ++i)
				for (int j = i + 1; j < i + 4; ++j)
					for (int k = j + 1; k < j + 4 && k < n; ++k)
					{
						string a = s.substr(0, i);
						string b = s.substr(i, j - i);
						string c = s.substr(j , k - j);
						string d = s.substr(k);
						if (valid(a) && valid(b) && valid(c) && valid(d))
							res.push_back(a + '.' + b + '.' + c + '.' + d);
					}
			return res;
		}
		bool valid(string t)
		{
			if (t.size() >= 4)
				return false;
			int a = stoi(t);
			return t == "0" || t[0] != '0' && a < 256;
		}
};
