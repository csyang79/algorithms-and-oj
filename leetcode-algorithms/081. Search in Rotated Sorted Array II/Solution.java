class Solution {
	public boolean search(int[] nums, int target) {
		int length = nums.length;
		if (length == 0)
			return false;
		int left = 0;
		int right = length - 1;
		int mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] > nums[right]) {
				if (nums[left] <= target && target <= nums[mid])
					right = mid;
				else
					left = mid + 1;
			} else if (nums[mid] < nums[right]) {
				if (nums[mid] < target && target <= nums[right])
					left = mid + 1;
				else 
					right = mid;
			} else {
				--right;
			}
		}
		return nums[left] == target;
	}
}
