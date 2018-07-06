//无重复，O(log n)，注意求最小索引的方法:nums[mid] > nums[right], left = mid + 1;
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if (nums.empty())
				return -1;
			int sz = nums.size();
			int left = 0, right = sz - 1;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (nums[mid] > nums[right])
					left = mid + 1;
				else
					right = mid;
			}
			int idx = left;
			left = 0;
			right = sz;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (nums[(mid + idx) % sz] < target)
					left = mid + 1;
				else
					right = mid;
			}
			return nums[(left + idx) % sz] == target ? (left + idx) % sz : -1;
		}
};

//注意边界条件
class Solution {
	public:
		int search(vector<int>& nums, int target) {
			if (nums.empty())
				return -1;
			int left = 0;
			int right = nums.size() - 1;
			int mid;
			int res;
			while (left < right)
			{
				mid = left + (right - left) / 2;
				if (nums[mid] > nums[right])
				{
					if (nums[left] <= target && target <= nums[mid])
						right = mid;
					else
						left = mid + 1;
				}
				else
				{
					if (nums[mid] < target && target <= nums[right])
						left = mid + 1;
					else 
						right = mid;
				}
			}
			return nums[left] == target ? left : -1;
		}
};
