//O(n^2)
class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());
			int ans, cur = INT_MAX, t;
			for (int i = 0; i < nums.size() - 2; ++i)
			{
				for (int j = i + 1, k = nums.size() - 1; j < k;)
				{
					t = nums[i] + nums[j] + nums[k];
					if (t == target)
						return target;
					if (std::abs(t - target) < cur)
					{
						ans = t;
						cur = abs(t - target);
					}
					if (t > target)
						--k;
					else 
						++j;
				}
			}
			return ans;
		}
};
