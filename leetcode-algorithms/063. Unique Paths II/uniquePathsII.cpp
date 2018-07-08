//注意每次dp[0]的变化
class Solution {
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
			if (obstacleGrid.empty() || obstacleGrid[0].empty())
				return 0;
			const int m = obstacleGrid.size();
			const int n = obstacleGrid[0].size();
			vector<int> dp(n, 1);
			for (int j = 0; j < n; ++j)
				if (obstacleGrid[0][j] == 1)
				{
					while (j < n)
						dp[j++] = 0; 
				}
			for (int i = 1; i < m; ++i)
			{
				dp[0] = obstacleGrid[i][0] == 1 ? 0 : dp[0];
				for (int j = 1; j < n; ++j)
				{
					dp[j] += dp[j - 1];
					if (obstacleGrid[i][j] == 1)
						dp[j] = 0;
				}
			}
			return dp[n - 1];
		}
};
