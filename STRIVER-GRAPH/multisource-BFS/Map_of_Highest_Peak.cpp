1765. Map of Highest Peak

class Solution {
public:
    // time o( n * m)
    // space o( n 8 m)
    typedef pair<int,int>p;
    vector<vector<int>>direction = {{0,-1},{0,1},{1,0},{-1,0}}; 
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        //  always start from cell 0
        // since dfs goes to depth depth depth 
        // so dfs will not help here normal bfs also do not work 

        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>>height(n, vector<int>(m , -1));
        queue<p>q;
        // since If the cell is a water cell, its height must be 0.
        for(int i = 0; i < n ; i++){ // o(n * m)
            for(int j = 0; j < m ; j++){
                if(isWater[i][j] == 1){
                    height[i][j] = 0; // source
                    q.push({i,j});
                }
            }
        }
        
        while( !q.empty()){ // o(n * m)
            int sz = q.size();

            while( sz --){
                auto p = q.front();
                q.pop();

                int i = p.first;
                int j = p.second;

                for(auto &dir : direction){
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >=0 && j_ >=0 && i_ < n && j_ < m && height[i_][j_] == -1){
                        height[i_][j_] = height[i][j] + 1;
                        q.push({i_ , j_});
                    }
                }
            }
        }
        return height;
    } 
};