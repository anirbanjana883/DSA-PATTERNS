778. Swim in Rising Water

class Solution {
public:
    // Time: O(n^2 * log n)
    // Space: O(n^2) 
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // min heap: {elevation, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        // Directions: right, left, down, up
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int result = 0;

        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int elevation = curr[0], x = curr[1], y = curr[2];
            result = max(result, elevation);

            if (x == n - 1 && y == n - 1) return result;

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }

        return -1; // Should never reach here
    }
};

approach 2 : binary search 

class Solution {
public:
    int n;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

    bool canReach(vector<vector<int>>& grid, int t, int x, int y, vector<vector<bool>>& visited) {
        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y] || grid[x][y] > t)
            return false;
        if (x == n - 1 && y == n - 1)
            return true;

        visited[x][y] = true;
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (canReach(grid, t, nx, ny, visited))
                return true;
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int lo = max(grid[0][0], grid[n-1][n-1]);
        int hi = -1e9;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < n ;j++){
                hi = max( hi , grid[i][j]);
            }
        }

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (canReach(grid, mid, 0, 0, visited)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
