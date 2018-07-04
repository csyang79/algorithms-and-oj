#include <iostream>
#include <climits>

using namespace std;

int reverse(int x)
{
	if (x == 0 || x == INT_MIN)
		return 0;
	int sign = x > 0 ? 1 : -1;
	x = x > 0 ? x : -x;
	int res = 0;
	while (x)
	{	
		int t = x % 10;
		if (res > INT_MAX / 10 || res == INT_MAX / 10 && t > 7)
			return 0;
		res = res * 10 + t;
		x /= 10;
	}
	return sign * res;
}

int main()
{
}
