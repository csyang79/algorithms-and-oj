//https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
//using recursion
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};
//using iteration
class Solution
{
public:
	int getSum(int a, int b)
	{
		do
		{
			int t = (a & b) << 1;
			a ^= b;
			b = t;		
		} while (b);
		return a;
	}
};

