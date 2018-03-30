//O(n^2) using dp
class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[1000][1000] = {0};
        return solve(dp, 1, n);
    }
    int solve(int dp[1000][1000], int start, int end)
    {
        if (start >= end)
            return 0;
        if (dp[start][end])
            return dp[start][end];
        dp[start][end] = INT_MAX;
        for (int i = start; i <= end; ++i)
            dp[start][end] = std::min(dp[start][end], i + std::max(solve(dp, start, i - 1), solve(dp, i + 1, end)));
        return dp[start][end];
    }
};
