//lower_bound和upper_bound，O(log n)
class Solution {
	public:
		vector<int> searchRange(vector<int>& nums, int target) {
			if (nums.empty())
				return {-1, -1};
			vector<int> res{ -1, -1 };
			int left = 0, right = nums.size();
			int mid;
			while (left < right)
			{
				mid = left + (right - left) / 2;
				if (nums[mid] < target)
					left = mid + 1;
				else
					right = mid;
			}

			//重要，注意
			if (left == nums.size() || nums[left] != target)
				return res;
			
			res[0] = left;

			left = 0, right = nums.size();
			while (left < right)
			{
				mid = left + (right - left) / 2;
				if (nums[mid] <= target)
					left = mid + 1;
				else
					right = mid;
			}
			res[1] = left - 1;
			return res;
		}
};
