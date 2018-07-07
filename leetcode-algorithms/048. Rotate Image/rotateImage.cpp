//矩阵90°旋转，reverse+对称
class Solution {
	public:
		void rotate(vector<vector<int>>& matrix) {
			if (matrix.empty() || matrix[0].empty())
				return;
			reverse(matrix.begin(), matrix.end());    
			for (int i = 0; i < matrix.size(); ++i)
				for (int j = 0; j < i; ++j)
					std::swap(matrix[i][j], matrix[j][i]);
		}
};
