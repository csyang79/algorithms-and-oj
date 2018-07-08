//all subsets,O(2^n)
class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<int> cur;
			vector<vector<int>> res;
			dfs(nums, 0, cur, res);
			return res;
		}
		void dfs(const vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res)
		{
			res.push_back(cur);
			for (int i = start; i < nums.size(); ++i)
			{
				cur.push_back(nums[i]);
				dfs(nums, i + 1, cur, res);
				cur.pop_back();
			}
		}
};

//bitOperation
class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			int i = 0;
			const int n = nums.size();
			vector<int> cur;
			vector<vector<int>> res;
			while (i < (1 << n))
			{
				cur.clear();
				for (int j = 0; j < 32; ++j)
					if ((i >> j) & 1)
						cur.push_back(nums[j]);
				++i;
				res.push_back(cur);
			}
			return res;
		}
};
