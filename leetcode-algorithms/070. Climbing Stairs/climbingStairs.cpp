//简单dp
class Solution {
	public:
		int climbStairs(int n) {
			int f = 1, g = 1;
			while (--n)
			{
				f += g;
				g = f - g;
			}
			return f;
		}
};
