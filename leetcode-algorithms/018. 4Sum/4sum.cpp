//O(n^3)
class Solution {
	public:
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			if (nums.size() < 4)
				return {};
			vector<vector<int>> result;
			int t1, t2, t3;
			sort(nums.begin(), nums.end());
			for (int i = 0; i < nums.size() - 3; ++i)
			{
				if (i != 0 && nums[i] == nums[i - 1])
					continue;
				t1 = target - nums[i];
				for (int j = i + 1; j < nums.size() - 2; ++j)
				{
					if (j != i + 1 && nums[j] == nums[j - 1])
						continue;
					t2 = t1 - nums[j];
					for (int k = j + 1, l = nums.size() - 1; k < l;)
					{
						if (k != j + 1 && nums[k] == nums[k - 1])
						{
							++k;
							continue;
						}
						t3 = nums[k] + nums[l];
						if (t3 == t2)
						{
							result.push_back({nums[i], nums[j], nums[k], nums[l]});
							++k;
							--l;
						}
						else if (t3 < t2)
							++k;
						else
							--l;
					}
				}
			}
			return result;
		}
};
