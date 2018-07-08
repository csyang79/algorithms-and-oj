//O(log m + log n)注意二分边界条件
class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if (matrix.empty() || matrix[0].empty())
				return false;
			const int m = matrix.size();
			const int n = matrix[0].size();
			int left = 0, right = m;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (matrix[mid][n - 1] < target)
					left = mid + 1;
				else
					right = mid;
			}
			if (left == m)
				return false;
			int idx = left;
			left = 0, right = n;
			while (left < right)
			{
				int mid = left + (right - left) / 2;
				if (matrix[idx][mid] < target)
					left = mid + 1;
				else 
					right = mid;
			}
			return matrix[idx][left] == target;
		}
}; 
