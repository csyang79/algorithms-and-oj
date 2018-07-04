class Solution {
	public:
		bool isPalindrome(int x) {
			if (x < 0 || x != 0 && x % 10 == 0)
				return false;
			int y = 0;
			int t;
			while (x > y)
			{
				t = x % 10;
				y = y * 10 + t;
				x /= 10;
			}
			if (y > x)
				y /= 10;
			return x == y;
		}
};
