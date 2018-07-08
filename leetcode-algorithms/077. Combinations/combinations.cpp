//subset, dfs
class Solution {
	public:
		vector<vector<int>> combine(int n, int k) {
			vector<int> nums(n);
			for (int i = 0; i < n; ++i)
				nums[i] = i + 1;
			vector<vector<int>> res;
			vector<int> cur;
			dfs(nums, 0, cur, res, k);
			return res;
		}
		void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res, int k)
		{
			if (cur.size() == k)
			{
				res.push_back(cur);
				return;
			}
			for (int i = start; i < nums.size(); ++i)
			{
				cur.push_back(nums[i]);
				dfs(nums, i + 1, cur, res, k);
				cur.pop_back();
			}
		}
};
