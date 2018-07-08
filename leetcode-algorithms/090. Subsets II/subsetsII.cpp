//含有重复元素
class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
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
				if (i != start && nums[i] == nums[i - 1])
					continue;
				cur.push_back(nums[i]);
				dfs(nums, i + 1, cur, res);
				cur.pop_back();
			}
		}
};
