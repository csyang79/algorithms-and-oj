//矩阵常用解法,r1r2c1c2
class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			if (matrix.empty() || matrix[0].empty())
				return {};
			int r1 = 0, r2 = matrix.size(), c1 = 0, c2 = matrix[0].size();
			vector<int> res;
			while (1)
			{
				for (int j = c1; j < c2; ++j)
					res.push_back(matrix[r1][j]);
				if (!(++r1 < r2))
					break;

				for (int i = r1; i < r2; ++i)
					res.push_back(matrix[i][c2 - 1]);
				if (!(c1 < --c2))
					break;

				for (int j = c2 - 1; j >= c1; --j)
					res.push_back(matrix[r2 - 1][j]);
				if (!(r1 < --r2))
					break;

				for (int i = r2 - 1; i >= r1; --i)
					res.push_back(matrix[i][c1]);
				if (!(++c1 < c2))
					break;
			}
			return res;
		}
};
