//实现myPow首先将指数变为正数，然后递归O(log n)
class Solution {
	public:
		double myPow(double x, int n) {
			if (n < 0)
				return (1 / x) * myPow(1 / x, -(n + 1));
			else if (n == 0)
				return 1;
			else
				return myPow(x * x, n / 2) * (( n & 1) ? x : 1);
		}
};
