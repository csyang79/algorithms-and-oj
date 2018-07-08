//O(n^2) time and O(n) space
//简单DP，初始化，转移即可
class Solution {
	public:
		int minPathSum(vector<vector<int>>& grid) {
			if (grid.empty() || grid[0].empty())
				return 0;
			const int m = grid.size();
			const int n = grid[0].size();
			vector<int> dp(n);
			dp[0] = grid[0][0];
			for (int i = 1; i < n; ++i)
				dp[i] = grid[0][i] + dp[i - 1];
			for (int i = 1; i < m; ++i)
			{
				dp[0] += grid[i][0];
				for (int j = 1; j < n; ++j)
					dp[j] = std::min(dp[j - 1], dp[j]) + grid[i][j];
			}
			return dp[n - 1];
		}
};
