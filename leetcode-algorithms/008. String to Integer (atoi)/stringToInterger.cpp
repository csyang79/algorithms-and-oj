class Solution {
	public:
		int myAtoi(string str) {
			const char *p = str.c_str();

			int res = 0;
			while (*p == ' ')
				++p;
			int flag = 1;
			if (*p == '+' || *p == '-')
			{
				flag = *p == '+' ? flag : -flag;
				++p;
			}
			while (*p >= '0' && *p <= '9')
			{
				if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (*p - '0') > INT_MAX % 10))
					return flag == 1 ? INT_MAX : INT_MIN;

				res = res * 10 + *p - '0';
				++p;
			}
			return res * flag;
		}
};
