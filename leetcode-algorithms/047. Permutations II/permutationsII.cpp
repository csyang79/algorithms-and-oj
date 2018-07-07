//note:nums参数为形参，不改变
class Solution {
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> result;
			dfs(nums, 0, result);
			return result;
		}
		void dfs(vector<int> nums, int start, vector<vector<int>>& result)
		{
			if (start == nums.size() - 1)
			{
				result.push_back(nums);
				return;
			}
			for (int i = start; i < nums.size(); ++i)
			{
				if (i != start && nums[i] == nums[start])
					continue;
				std::swap(nums[start], nums[i]);
				dfs(nums, start + 1, result);
			}
		}

};


