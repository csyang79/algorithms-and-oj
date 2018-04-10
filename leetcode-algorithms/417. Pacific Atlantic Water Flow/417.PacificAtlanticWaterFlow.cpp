class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if (matrix.empty() || matrix[0].empty())
            return result;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            dfs(matrix, i, 0, INT_MIN, 1, visited, result);
            dfs(matrix, i, n - 1, INT_MIN, 2, visited, result);
        }
        for (int j = 0; j < n; ++j)
        {
            dfs(matrix, 0, j, INT_MIN, 1, visited, result);
            dfs(matrix, m - 1, j, INT_MIN, 2, visited, result);
        }
        return result;
    }
    void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int from, vector<vector<int>>& visited, vector<pair<int, int>>& result)
    {
        if (x < 0 || x == matrix.size() || y < 0 || y == matrix[0].size() || matrix[x][y] < pre || (from & visited[x][y]) == from)
            return ;
        visited[x][y] |= from;
        if (visited[x][y] == 3)
            result.push_back(make_pair(x, y));
        dfs(matrix, x - 1, y, matrix[x][y], from, visited, result);
        dfs(matrix, x + 1, y, matrix[x][y], from, visited, result);
        dfs(matrix, x, y - 1, matrix[x][y], from, visited, result);
        dfs(matrix, x, y + 1, matrix[x][y], from, visited, result);
    }
};


