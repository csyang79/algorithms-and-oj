//O(m*n)，模拟乘法
class Solution {
	public:
		string multiply(string num1, string num2) {
			if (num1.empty() || num2.empty())
				return "0";
			const int m = num1.size();
			const int n = num2.size();
			string result(m + n, '0');
			int carry, t;
			for (int i = n - 1; i >= 0; --i)
			{
				carry = 0;
				for (int j = m - 1; j >= 0; --j)
				{
					t = (num1[j] - '0') * (num2[i] - '0') + carry + result[i + j + 1] - '0';
					carry = t / 10;
					result[i + j + 1] = t % 10 + '0';
				}
				result[i] = carry + '0';
			}

			int s;
			for (s = 0; s < result.size() && result[s] == '0'; ++s);
			return s == result.size() ? "0" : result.substr(s, m + n);
		}
};
