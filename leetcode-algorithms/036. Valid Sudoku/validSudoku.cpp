//O(1) space
class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			bool tmp[9];
			for (int i = 0; i < 9; ++i)
			{
				fill_n(tmp, 9, false);
				for (int j = 0; j < 9; ++j)
				{
					if (board[i][j] == '.')
						continue;
					if (tmp[board[i][j] - '1'])
						return false;
					tmp[board[i][j] - '1'] = true;
				}
				fill_n(tmp, 9, false);
				for (int j = 0; j < 9; ++j)
				{
					if (board[j][i] == '.')
						continue;
					if (tmp[board[j][i] - '1'])
						return false;
					tmp[board[j][i] - '1'] = true;
				}
			}
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					fill_n(tmp, 9, false);
					for (int k = i * 3; k < i * 3 + 3; ++k)
						for (int l = j * 3; l < j * 3 + 3; ++l)
						{
							if (board[k][l] == '.')
								continue;
							if (tmp[board[k][l] - '1'])
								return false;
							tmp[board[k][l] - '1'] = true;
						}
				}
			}
			return true;
		}
};
