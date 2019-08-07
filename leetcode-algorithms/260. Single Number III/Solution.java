class Solution {
	public int[] singleNumber(int[] nums) {
		int xorRes = 0;
		for (int num : nums) {
			xorRes ^= num;
		}
		// 取最低位的1
		xorRes &= -xorRes;

		int[] res = new int[]{0, 0};
		for (int num : nums) {
			if ((num & xorRes) == 0) {
				res[0] ^= num;
			} else {
				res[1] ^= num;
			}
		}
		return res;
	}
}
