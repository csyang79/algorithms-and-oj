//O(n) time and O(1) space，最大和子数组
class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int max_sum = INT_MIN;
			int cur = 0;
			for (int i = 0; i < nums.size(); ++i)
			{
				cur += nums[i];
				max_sum = cur > max_sum ? cur : max_sum;
				if (cur < 0)
					cur = 0;
			}
			return max_sum;
		}
};
