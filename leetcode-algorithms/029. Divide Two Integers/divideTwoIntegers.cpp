//O(logn)，用减法模拟除法，用负数运算防止溢出，除数加倍用来优化复杂度
class Solution {
	public:
		int divide(int dividend, int divisor) {
			if (dividend == INT_MIN && divisor == -1)
				return INT_MAX;
			if (dividend == 0)
				return 0;
			bool flag;
			if (dividend < 0 && divisor < 0 || dividend > 0 && divisor > 0)
				flag = 1;
			else
				flag = 0;
			if (dividend > 0)
				dividend = -dividend;
			if (divisor > 0)
				divisor = -divisor;
			if (dividend > divisor)
				return 0;
			int count = 1;
			int res = 0;
			while (count != 0)
			{
				dividend -= divisor;
				res += count;
				if ((dividend >> 1) < divisor)
				{
					divisor <<= 1;
					count <<= 1;
				}
				while (count != 0 && dividend > divisor)
				{
					divisor >>= 1;
					count >>= 1;
				}
			}
			return flag ? res : -res;
		}
};
