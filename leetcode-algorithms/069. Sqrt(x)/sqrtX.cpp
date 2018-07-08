//newton's method, conner case: 0
class Solution {
	public:
		int mySqrt(int x) {
			if (x == 0)
				return 0;
			double t1 = x, t2;
			while (t1 - (t2 = (t1 + x / t1) / 2) > 0.000001)
				t1 = t2;
			return static_cast<int>(t2);
		}
};
