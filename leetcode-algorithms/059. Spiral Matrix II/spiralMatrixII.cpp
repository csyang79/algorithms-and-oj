class Solution {
	public:
		vector<vector<int>> generateMatrix(int n) {
			if (n <= 0)
				return {};
			int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
			vector<vector<int>> res(n, vector<int>(n));
			int count = 0;
			while (1)
			{
				for (int j = c1; j <= c2; ++j)
					res[r1][j] = ++count;
				if (++r1 > r2)
					break;

				for (int i = r1; i <= r2; ++i)
					res[i][c2] = ++count;
				if (c1 > --c2)
					break;

				for (int j = c2; j >= c1; --j)
					res[r2][j] = ++count;
				if (r1 > --r2)
					break;

				for (int i = r2; i >= r1; --i)
					res[i][c1] = ++count;
				if (++c1 > c2)
					break;
			}
			return res;
		}
};
