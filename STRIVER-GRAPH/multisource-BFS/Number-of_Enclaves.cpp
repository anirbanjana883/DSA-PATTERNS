1020. Number of Enclaves

class Solution {
public:
    // Time Complexity: O(n × m) 
    // Space Complexity: O(n × m) 
    vector<vector<int>>direction = {{0 , -1},{0 , 1},{1, 0 },{-1 , 0}};
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m  ; j++){
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    if(grid[i][j] == 1){
                        q.push({i , j});
                        grid[i][j] = 0;
                    }
                }
            }
        }

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            for(auto &dir:direction){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && j_ >= 0 && i_ < n && j_ < m && grid[i_][j_] == 1){
                    q.push({i_ , j_});
                    grid[i_][j_] = 0;
                }   
            }
        }

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m ;j++){
                if(grid[i][j] == 1){
                    cnt ++;
                }
            }
        }

        return cnt;
    }
};