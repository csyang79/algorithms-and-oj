class Solution {
	public int search(int[] nums, int target) {
		int length = nums.length;
		if (length == 0)
			return -1;
		int left = 0, right = length - 1;
		int mid;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[mid] > nums[right])
				left = mid + 1;
			else
				right = mid;
		}
		int rotate = left;
		left = 0;
		right = length;
		while (left < right) {
			mid = left + (right - left) / 2;
			if (nums[(mid + rotate) % length] < target)
				left = mid + 1;
			else
				right = mid;
		}
		if (nums[(left + rotate) % length] == target)
			return (left + rotate) % length;
		else
			return -1;
	}   
}
