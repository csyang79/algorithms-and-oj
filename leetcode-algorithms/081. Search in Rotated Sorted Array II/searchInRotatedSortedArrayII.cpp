//无法AC，conner case 11131，无法取得重复元素旋转数组最小值的第一个索引
class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			if (nums.empty())
				return false;
			int len = nums.size();
			int left = 0, right = len - 1;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] > nums[right])
					left = mid + 1;
				else if (nums[mid] < nums[right])
					right = mid;
				else
					--right;
			}

			int idx = left;
			left = 0, right = len;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (nums[(idx + mid) % len] < target)
					left = mid + 1;
				else
					right = mid;
			}
			return nums[(left + idx) % len] == target;
		}
};


//利用旋转数组一半有序，最坏O(n)，平均O(log n)
class Solution {
	public:
		bool search(vector<int>& nums, int target) {
			if (nums.empty())
				return false;
			int left = 0, right = nums.size();
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] == target)
					return true;
				if (nums[mid] > nums[right - 1])
				{
					if (nums[left] <= target && target < nums[mid])
						right = mid;
					else
						left = mid + 1;
				}
				else if (nums[mid] < nums[right - 1])
				{
					if (nums[mid] < target && target <= nums[right - 1])
						left = mid + 1;
					else
						right = mid;
				}
				else
					--right;
			}
			return false;
		}
};
