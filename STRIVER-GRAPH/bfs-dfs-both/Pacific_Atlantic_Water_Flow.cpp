417. Pacific Atlantic Water Flow

1. DFS Approach :
the first row and first col touch pacific
the last row and last col touch atlantic
so we will find all the cell in dfs with these cell and have height greater then it

class Solution {
public: 
    // time o(2 * m * n)
    // space o(2 * m * n)
    vector<vector<int>> direction = {{0,-1},{0,1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& grid , vector<vector<bool>>&vis , int i , int j ,
    int orgi , int orgj){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j]) return;
        if(orgi >= 0 && orgj >= 0 && grid[i][j] < grid[orgi][orgj]) return;

        vis[i][j] = true;
        for(auto &dir:direction){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            dfs(grid, vis, i_, j_, i, j);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>>pac(n,vector<bool>(m,false)); // true means water can go to pacific
        vector<vector<bool>>atl(n,vector<bool>(m,false));// true means water can go to atlantic


        for(int i = 0; i < n  ;i++){
            dfs(grid, pac, i, 0, -1, -1); // first col
            dfs(grid, atl, i, m-1, -1, -1); // last col
        }
        for(int j = 0; j < m  ;j++){
            dfs(grid, pac, 0, j, -1, -1); // first row
            dfs(grid, atl, n-1, j, -1, -1); // last row
        }

        for(int i = 0; i < n; i++){
            for(int j = 0 ;  j < m ;j++){
                if(pac[i][j] && atl[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
2. BFS Approach :

class Solution {
public:

    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &vis, vector<vector<int>>& heights, int n, int m)
    {
        vector<int>dx = {-1, 0, 1, 0};
        vector<int>dy = {0, -1, 0, 1};
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            vis[r][c] = true; // mark visited

            for(int i=0;i<4;i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >=0 && nr < n && nc >=0 && nc < m && heights[r][c] <= heights[nr][nc] && !vis[nr][nc]) {
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m)); // visited array
        vector<vector<bool>> atl(n, vector<bool>(m));
        queue<pair<int,int>>q;

        // push cells connected to pacific ocean
        for(int i=n-1;i>=0;i--) q.push({i, 0}); // first col 
        for(int i=m-1;i>=0;i--) q.push({0, i}); // first row

        bfs(q, pac, heights, n, m);

        // push cells connected to atlantic ocean
        for(int i=n-1;i>=0;i--) q.push({i, m-1}); // last col
        for(int i=m-1;i>=0;i--) q.push({n-1, i}); // last row

        bfs(q, atl, heights, n, m);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};