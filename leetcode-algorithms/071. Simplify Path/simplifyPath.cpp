//体会istringstream用法，以及getline函数
//path = "/a/./b/../../c/" to "/c"
class Solution {
	public:
		string simplifyPath(string path) {
			string tmp, res;
			istringstream in(path);
			vector<string> stk;
			while (getline(in, tmp, '/'))
			{
				if (tmp == "" || tmp == ".")
					continue;
				if (tmp == "..")
				{
					if (!stk.empty())
						stk.pop_back();
				}
				else
					stk.push_back(tmp);
			}
			for (string str : stk)
				res += "/" + str;
			return res.empty() ? "/" : res;
		}
};
