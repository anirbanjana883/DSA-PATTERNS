200. Number of Islands

approach 1: dfs
t.c o(n*m)
s.c o(n*m) recursn stack place 

class Solution {
    public:
        int n;
        int m;
        vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
        void DFS(vector<vector<char>>& grid,int i,int j){
            grid[i][j]='#';
            for(auto &dir:direction){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if (i_ < 0 || i_ >= n || j_ < 0 || j_ >= m || grid[i_][j_] != '1') {
                    continue;
                }
                DFS(grid,i_,j_);
            }
            return;
        }
        int numIslands(vector<vector<char>>& grid) {
            n=grid.size();
            m=grid[0].size();
    
            int island=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]=='1'){
                        DFS(grid,i,j);
                        island++;
                    }
                }
            }
            return island;
    
        }
    };

approach 2:  bfs 
Time Complexity: O(n * m)

Space Complexity: O(min(n, m))

class Solution {
    public:
        int n;
        int m;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        void BFS(vector<vector<char>>& grid, int i, int j) {
            queue<pair<int, int>> q;
            q.push({i, j});
            grid[i][j] = '#';
    
            while (!q.empty()) {
                auto it = q.front();
                q.pop();
    
                for (auto& dir : direction) {
                    int i_ = it.first + dir[0];
                    int j_ = it.second + dir[1];
    
                    if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
                        grid[i_][j_] == '1') {
                        q.push({i_, j_});
                        grid[i_][j_] = '#';
                    }
                }
            }
            return;
        }
        int numIslands(vector<vector<char>>& grid) {
            n = grid.size();
            m = grid[0].size();
    
            int island = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '1') {
                        BFS(grid, i, j);
                        island++;
                    }
                }
            }
            return island;
        }
    };