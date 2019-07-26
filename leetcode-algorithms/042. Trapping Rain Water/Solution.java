//O(n)
class Solution {
	public int trap(int[] height) {
		if (height == null || height.length == 0)
			return 0;
		int left = 0, right = height.length - 1;
		int level = 0;
		int lower;
		int res = 0;
		while (left < right) {
			lower = height[height[left] < height[right] ? left++ : right--];
			level = Math.max(level, lower);
			res += level - lower;
		}
		return res;
	}
}
