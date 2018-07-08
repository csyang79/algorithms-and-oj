//note:note if (nums[i] != nums[i - 2]), why? nums[i - 2]已经是被更新过的值了
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			if (nums.size() < 3)
				return nums.size();
			int k = 1;
			for (int i = 2; i < nums.size(); ++i)
				if (nums[i] != nums[k - 1])
					nums[++k] = nums[i];
			return ++k;
		}
};
