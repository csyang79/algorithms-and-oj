class Solution {
	public int removeDuplicates(int[] nums) {
		int length = nums.length;
		if (length < 3)
			return length;
		int i = 2;
		for (int j = 2; j < length; ++j) {
			if (nums[j] != nums[i - 2])
				nums[i++] = nums[j];
		}
		return i;
	}
}
