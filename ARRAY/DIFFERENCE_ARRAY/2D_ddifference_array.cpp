2D Difference Array

class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> diff(n + 1, vector<int>(m + 1 ,0));
        
        // 1. Collect all diff updates first
        for (auto &it : opr) {
            int val = it[0];
            int r1 = it[1];
            int c1 = it[2];
            int r2 = it[3];
            int c2 = it[4];
            
            diff[r1][c1] += val;
            diff[r1][c2 + 1] -= val;
            diff[r2 + 1][c1] -= val;
            diff[r2 + 1][c2 + 1] += val;
        }
        
        // 2. Prefix sum across rows
        for (int r = 0 ; r < n ; r++) {
            for (int c = 1 ; c < m ; c++) {
                diff[r][c] += diff[r][c - 1];
            }
        }
        
        // 3. Prefix sum across columns
        for (int c = 0 ; c < m ; c++) {
            for (int r = 1 ; r < n ; r++) {
                diff[r][c] += diff[r - 1][c];
            }
        }
        
        // 4. Apply the final difference to original matrix
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                mat[i][j] += diff[i][j];
            }
        }

        return mat;
    }
};
