class Solution {
public:
    int integerBreak(int n) {
        if (n < 4)
            return n - 1;
        int ans = 1;
        while (n > 4)
        {
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;
    }
};
//if factor n >= 4, then 2(n-2) >= n exists, so factor should be 2 or 3,
//note 3 * 3 > 2 * 2 * 2, so 2 should not appear more than twice.
