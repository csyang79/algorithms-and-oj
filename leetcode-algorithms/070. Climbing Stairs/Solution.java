class Solution {
	public int climbStairs(int n) {
		int f = 1;
		int g = 1;
		while (--n != 0) {
			f += g;
			g = f - g;
		}
		return f;
	}
}
