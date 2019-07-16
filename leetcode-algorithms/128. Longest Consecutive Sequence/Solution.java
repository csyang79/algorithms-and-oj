class Solution {
	public int longestConsecutive(int[] nums) {
		final HashSet<Integer> mySet = new HashSet<>();
		for (int i : nums)
			mySet.add(i);
		int result = 0;
		for (int i : nums) {
			if (mySet.contains(i)) {
				int l = 1, r = 1;
				while (mySet.contains(i - l)) {
					mySet.remove(i - l++);
				}
				while (mySet.contains(i + r)) {
					mySet.remove(i + r++);
				}
				result = Math.max(result, l + r - 1);
			}
		}
		return result;
	}
}
