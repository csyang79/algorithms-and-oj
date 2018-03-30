//O(nlog(max-min))

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1], mid;
        while (left < right)				//O(log(max - min))
        {
            mid = left + (right - left) / 2;
            int count = 0, j = n - 1;
            for (int i = 0; i < n; ++i)			//note: j from n - 1 to 0 while i from 0 to n -1, complexity should be(O(n))	
            {
                while (j >= 0 && matrix[i][j] > mid)
                    --j;
                count += j + 1;
            }
            if (count < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
