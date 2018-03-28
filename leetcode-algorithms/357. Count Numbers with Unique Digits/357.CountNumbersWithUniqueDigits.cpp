//f(0) == 1, f(1) == 10, f(2) == 9 * 9, f(3) == 9 * 9 * 8 ..., f(11) == 0

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10)
            return 0;
        if (n == 0)
            return 1;
        int ans = 10;
        int cur = 9;
        for (int i = 2; i <= n; ++i)
        {
            cur *= 11 - i;
            ans += cur;
        }
        return ans;
    }
};
