//O(n)
class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			int i = -1;
			for (int j = 0; j < nums.size(); ++j)
				if (nums[j] != val)
					nums[++i] = nums[j];
			return i + 1;
		}
};
