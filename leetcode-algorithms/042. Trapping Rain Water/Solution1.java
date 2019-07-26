//好久没写之后的挫代码,遍历三次,代码一大堆
class Solution1 {
	public int trap(int[] height) {
		if (height == null || height.length == 0)
			return 0;
		int maxIndex = 0;
		for (int i = 1; i < height.length; ++i) {
			if (height[i] > height[maxIndex])
				maxIndex = i;
		}
		int[] moreHeight = new int[height.length];
		int currMax = height[0];
		moreHeight[maxIndex] = height[maxIndex];
		for (int i = 0; i < maxIndex; ++i) {
			if (height[i] > currMax) {
				currMax = height[i];
				moreHeight[i] = height[i];
			}
			else
				moreHeight[i] = currMax;
		}
		currMax = height[height.length - 1];
		for (int j = height.length - 1; j > maxIndex; --j) {
			if (height[j] > currMax) {
				currMax = height[j];
				moreHeight[j] = height[j];
			}
			else
				moreHeight[j] = currMax;
		}
		int res = 0;
		for (int i = 0; i < height.length; ++i) {
			res += moreHeight[i] - height[i];
		}
		return res;
	}
}
