2658. Maximum Number of Fish in a Grid

dfs :

class Solution {
public:
    int m,n;
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i,int j,vector<vector<int>>& grid){
        // checking if we have reached the boundary
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0){
            return 0;
        }
        int fishCount=grid[i][j];
        // as we take fish then 
        grid[i][j]=0;
        // check from this cell where we can go 
        for(auto vec:direction){
           int i_=i+vec[0];
            int j_=j+vec[1];
            fishCount+=dfs(i_,j_,grid);
        }
        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int maxFishCount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxFishCount=max(maxFishCount,dfs(i,j,grid));
            }
        }
        return maxFishCount;
    }
};

bfs :

class Solution {
public:
    int m, n;
    vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        que.push({i, j});
        int fishCount = grid[i][j];
        // Mark the cell as visited
        grid[i][j] = 0;

        while (!que.empty()) {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            // Explore all 4 directions
            for (auto vec : direction) {
                int nx = x + vec[0];
                int ny = y + vec[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] > 0) {
                    que.push({nx, ny});
                    fishCount += grid[nx][ny];
                    // Mark as visited
                    grid[nx][ny] = 0;
                }
            }
        }
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        n = grid.size();
        m = grid[0].size();
        int maxFishCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    maxFishCount = max(maxFishCount, bfs(i, j, grid));
                }
            }
        }
        return maxFishCount;
    }
};
