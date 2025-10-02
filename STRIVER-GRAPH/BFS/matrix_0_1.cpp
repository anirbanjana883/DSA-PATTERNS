542. 01 Matrix

class Solution {
public:
    // time o( n * m)
    // space o( n * m)
    vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> result(n, vector<int>(m, -1));
        //  multii source bfs
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            for (auto& dir : direction) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && result[i_][j_] == -1) {
                    q.push({i_, j_});
                    result[i_][j_] = result[i][j] + 1;
                }
            }
        }
        return result;
    }
};