130. Surrounded Regions

class Solution {
public:
    // time o ( n * m)
    // space o( n * m)
    int n;
    int m;
    vector<vector<char>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (auto& dir : direction) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < m &&
                visited[i_][j_] == false && grid[i_][j_] == 'O') {
                dfs(grid, i_, j_, visited);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        // a boundary 0 can not be sourrouindede by x
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        // for the first and last column
        for (int i = 0; i < n; i++) {
            // first col
            if (!visited[i][0] && grid[i][0] == 'O') {
                dfs(grid, i, 0, visited);
            }
            // last col
            if (!visited[i][m - 1] && grid[i][m - 1] == 'O') {
                dfs(grid, i, m - 1, visited);
            }
        }
        // for the forst row and last row
        for (int j = 0; j < m; j++) {
            // first row
            if (!visited[0][j] && grid[0][j] == 'O') {
                dfs(grid, 0, j, visited);
            }
            // last row
            if (!visited[n - 1][j] && grid[n - 1][j] == 'O') {
                dfs(grid, n - 1, j, visited);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};