class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        int m = matrix.size(), n = m == 0 ? 0 : matrix[0].size();	
        accu = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));	//clever
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                accu[i][j] = matrix[i - 1][j - 1] + accu[i - 1][j] + accu[i][j - 1] - accu[i - 1][j - 1];        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return accu[row2 + 1][col2 + 1] - accu[row1][col2 + 1] - accu[row2 + 1][col1] + accu[row1][col1];
    }
private:
    vector<vector<int>> accu;
};

