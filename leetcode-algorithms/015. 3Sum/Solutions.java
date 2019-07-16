class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		final int length = nums.length;
		List<List<Integer>> result = new ArrayList<>();
		Arrays.sort(nums);
		for (int i = 0; i < length - 2; ++i) {
			if (i != 0 && nums[i] == nums[i - 1])
				continue;
			int target = -nums[i];
			for (int j = i + 1, k = length - 1; j < k;) {
				if (j != i + 1 && nums[j] == nums[j - 1]) {
					++j;
					continue;
				}
				int sum = nums[j] + nums[k];
				if (sum == target) {
					result.add(Arrays.asList(nums[i], nums[j++], nums[k--]));
				}
				else if (sum < target)
					++j;
				else
					--k;
			}
		}
		return result;
	}
}
