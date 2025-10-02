463. Island Perimeter

approach 1: dfs

time complexity : o(n*m)
space complexity : o(1)

class Solution {
    public:
        int n;
        int m;
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        void DFS(vector<vector<int>>& grid, int i, int j, int& per) {
            // out of bound or zero then only have peremeter
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
                per++;
                return;
            }
            // if the cell is already visited
            if (grid[i][j] == -1)
                return;
    
            grid[i][j] = -1;
    
            for (auto& dir : direction) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
    
                DFS(grid, i_, j_, per);
            }
    
            return;
        }
        int islandPerimeter(vector<vector<int>>& grid) {
            n = grid.size();
            m = grid[0].size();
    
            int peremeter = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        DFS(grid, i, j, peremeter);
                    }
                }
            }
            return peremeter;
        }
    };

    approach 1: bfs

    time complexity : o(n*m)
    space complexity : o(n*m) size of queue

    class Solution {
        public:
            int n;
            int m;
            vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            void BFS(vector<vector<int>>& grid, int i, int j, int& per) {
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = -1;
        
                while (!q.empty()) {
                    auto it = q.front();
                    q.pop();
                    // it.first =i
                    // it.second=j
                    for (auto& dir : direction) {
                        int i_ = it.first + dir[0];
                        int j_ = it.second + dir[1];
                       
                        if (i_ < 0 || i_ >= n || j_ < 0 || j_ >= m || grid[i_][j_] == 0) {
                            per++;
                        }else if(grid[i_][j_]==-1){
                            continue;
                        }else{
                            q.push({i_,j_});
                            grid[i_][j_]=-1;
                        }
                    }
                }
            }
            int islandPerimeter(vector<vector<int>>& grid) {
                n = grid.size();
                m = grid[0].size();
        
                int peremeter = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (grid[i][j] == 1) {
                            BFS(grid, i, j, peremeter);
                        }
                    }
                }
                return peremeter;
            }
        };



Approach-3 (Iterative)
T.C : O(m*n)
S.C : O(1)
class Solution {
    public:
        int islandPerimeter(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            
            int perimeter = 0;
            for(int i = 0; i<m; i++) {
                for(int j = 0; j<n; j++) {
                    if(grid[i][j] == 0)
                        continue;
                    
                    if(i-1 < 0 || grid[i-1][j] == 0) //up
                        perimeter++;
                    
                    if(i+1 >= m || grid[i+1][j] == 0) //down
                        perimeter++;
                    
                    if(j-1 < 0 || grid[i][j-1] == 0) //left
                        perimeter++;
                    
                    if(j+1 >= n || grid[i][j+1] == 0) //right
                        perimeter++;
                    
                }
            }
            
            return perimeter;
        }
    };
    