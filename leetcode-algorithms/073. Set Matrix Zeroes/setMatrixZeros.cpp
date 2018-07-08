//O(n^2)time and O(1) space，复用第一行和第一列
class Solution {
	public:
		void setZeroes(vector<vector<int>>& matrix) {
			if (matrix.empty() || matrix[0].empty())
				return;
			bool row0 = false, col0 = false;
			for (int j = 0; j < matrix[0].size(); ++j)
				if (matrix[0][j] == 0)
				{
					row0 = 1;
					break;
				}
			for (int i = 0; i < matrix.size(); ++i)
				if (matrix[i][0] == 0)
				{
					col0 = 1;
					break;
				}
			for (int i = 1; i < matrix.size(); ++i)
				for (int j = 1; j < matrix[0].size(); ++j)
					if (matrix[i][j] == 0)
					{
						matrix[i][0] = 0;
						matrix[0][j] = 0;
					}
			for (int i = 1; i < matrix.size(); ++i)
				if (matrix[i][0] == 0)
					fill(matrix[i].begin(), matrix[i].end(), 0);
			for (int j = 1; j < matrix[0].size(); ++j)
				if (matrix[0][j] == 0)
					for (int i = 0; i < matrix.size(); ++i)
						matrix[i][j] = 0;
			if (row0)
				fill(matrix[0].begin(), matrix[0].end(), 0);
			if (col0)
			{
				for (int i = 0; i < matrix.size(); ++i)
					matrix[i][0] = 0;
			}
			return;
		}
};
