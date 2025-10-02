Number of Distinct Islands

class Solution {
public:
    // time o ( n * m)
    // space o ( n * m)
    int n, m;
    vector<vector<int>> direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited,
             int row0, int col0, vector<pair<int, int>>& vec) {
        visited[row][col] = true;
        vec.push_back({row - row0, col - col0});

        for (auto& dir : direction) {
            int row_ = row + dir[0];
            int col_ = col + dir[1];

            if (row_ >= 0 && col_ >= 0 && row_ < n && col_ < m &&
                !visited[row_][col_] && grid[row_][col_] == 1) {
                dfs(row_, col_, grid, visited, row0, col0, vec);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Use a set of strings or serialize vector<pair<int,int>> to string
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, visited, i, j, vec);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};
