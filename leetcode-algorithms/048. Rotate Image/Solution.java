class Solution {
	public void rotate(int[][] matrix) {
		if (matrix == null || matrix.length == 0)
			return;
		int n = matrix.length;
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			int[] tmp = matrix[i];
			matrix[i] = matrix[j];
			matrix[j] = tmp;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				int t = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = t;
			}
		}
	}
}
