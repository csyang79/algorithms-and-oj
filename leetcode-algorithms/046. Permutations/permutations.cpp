//dfs，注意for循环写法
//全排列的迭代解法即反复调用next_permutation
class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> result;
			vector<int> cur;
			dfs(nums, 0, cur, result);
			return result;
		}
		void dfs(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& result)
		{
			if (start == nums.size())
			{
				result.push_back(cur);
				return;
			}
			for (int i = start; i < nums.size(); ++i)
			{
				std::swap(nums[i], nums[start]);
				cur.push_back(nums[start]);
				dfs(nums, start + 1, cur, result);
				cur.pop_back();
				std::swap(nums[i], nums[start]);
			}
		}
};
