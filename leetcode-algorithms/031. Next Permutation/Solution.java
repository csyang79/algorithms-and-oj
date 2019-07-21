class Solution {
	public void nextPermutation(int[] nums) {
		int length = nums.length;
		if (length < 2)
			return ;
		int k = length - 2;
		while (k >= 0 && nums[k] >= nums[k + 1]) {
			--k;
		}
		if (k == -1) {
			reverse(nums, 0, length - 1);
			return;
		} 
		int tar = 0;
		for (int i = length - 1; i > k; --i)
			if (nums[i] > nums[k]) {
				tar = i;
				break;
			}
		swap(nums, k, tar);
		reverse(nums, k + 1, length - 1);
	}
	private void reverse(int[] nums, int i, int j) {
		while (i < j) {
			swap(nums, i, j);
			++i;
			--j;
		}
	}
	private void swap(int[] nums, int i, int j) {
		int t = nums[i];
		nums[i] = nums[j];
		nums[j] = t;
	}
}
