class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> result;
			if (nums.size() < 3)
				return result;
			sort(nums.begin(), nums.end());
			int s, t;
			for (int i = 0; i < nums.size() - 2; ++i)
			{
				s = -nums[i];
				if (i != 0 && nums[i] == nums[i - 1])
					continue;
				for (int j = i + 1, k = nums.size() - 1; j < k;)
				{
					if (j != i + 1 && nums[j] == nums[j - 1])
					{
						++j;
						continue;
					}
					t = nums[k] + nums[j];
					if (t == s)
						result.push_back({nums[i], nums[j++], nums[k--]});
					else if (t < s)
						++j;
					else
						--k;
				}
			}
			return result;
		}
};
