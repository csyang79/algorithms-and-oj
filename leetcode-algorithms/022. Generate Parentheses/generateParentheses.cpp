//dfs, O(2^n)
class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			if (n == 0)
				return {};
			vector<string> ans;
			string cur;
			generate(n, n, cur, ans);
			return ans;
		}
	private:
		void generate(int l, int r, string& cur, vector<string>& ans)
		{
			if (l == 0)
			{
				ans.push_back(cur + string(r, ')'));
				return;
			}
			cur.push_back('(');
			generate(l - 1, r, cur, ans);
			cur.pop_back();
			if (l < r)
			{
				cur.push_back(')');
				generate(l, r - 1, cur, ans);
				cur.pop_back();
			}
		}
};
