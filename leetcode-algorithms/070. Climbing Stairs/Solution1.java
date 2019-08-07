class Solution1 {
	public int climbStairs(int n) {
		int f = 1;
		int g = 2;
		for (int i = 3; i <= n; ++i) {
			g = f + g;
			f = g - f;
		}
		return n == 1 ? 1 : g;
	}
}
