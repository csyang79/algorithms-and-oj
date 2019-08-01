class Solution1 {
	public int[] plusOne(int[] digits) {
		int n = digits.length;
		int index = n - 1;
		for (; index >= 0 && digits[index] == 9; --index) {
			digits[index] = 0;
		}
		if (index == -1) {
			int[] result = new int[n + 1];
			result[0] = 1;
			return result;
		}
		digits[index] += 1;
		return digits;

	}
}
