class Solution {
	public boolean isValidSudoku(char[][] board) {
		boolean[] used = new boolean[9];
		for (int i = 0; i < 9; ++i) {
			Arrays.fill(used, false);
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				if (used[board[i][j] - '1'])
					return false;
				used[board[i][j] - '1'] = true;
			}
		}
		for (int i = 0; i < 9; ++i) {
			Arrays.fill(used, false);
			for (int j = 0; j < 9; ++j) {
				if (board[j][i] == '.')
					continue;
				if (used[board[j][i] - '1'])
					return false;
				used[board[j][i] - '1'] = true;
			}
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				Arrays.fill(used, false);
				for (int k = 0; k < 3; ++k) {
					for (int l = 0; l < 3; ++l) {
						if (board[3 * i + k][3 * j + l] == '.')
							continue;
						if (used[board[3 * i + k][3 * j + l] - '1'])
							return false;
						used[board[3 * i + k][3 * j + l] - '1'] = true;
					}
				}
			}
		}
		return true;
	}
}
