//维护一个目前可到达的变量
class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int cur = 0;
			const int sz = nums.size();
			for (int i = 0; i <= cur && cur < sz - 1; ++i)
				cur = i + nums[i] > cur ? i + nums[i] : cur;
			return cur >= sz - 1;
		}
};
