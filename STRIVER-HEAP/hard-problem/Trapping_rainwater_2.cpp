407. Trapping Rain Water II



class Solution {
public:     
    // time o( m * n) * log ( m * n)
    // space o( m * n)
    typedef pair<int,pair<int,int>>pp;
    vector<vector<int>>direction = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<pp , vector<pp> , greater<pp>>boundaryCells;
        vector<vector<bool>>visited(m,vector<bool>(n , false));

        // left most and right most column
        for(int row = 0 ; row < m ; row ++){
            for(int col : {0 , n-1}){
                boundaryCells.push({heightMap[row][col] , {row,col}});
                visited[row][col] = true;
            }
        }

        // topmost and bottommost column
        for(int col = 0 ; col < n ; col ++){
            for(int row : {0 , m-1}){
                boundaryCells.push({heightMap[row][col] , {row,col}});
                visited[row][col] = true;
            }
        }

        int water = 0;

        while(!boundaryCells.empty()){
            pp p = boundaryCells.top(); // log ( m * n )a at worst case
            boundaryCells.pop();
            int height = p.first;
            int i = p.second.first;
            int j = p.second.second;

            for(auto &dir:direction){
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && !visited[i_][j_]){
                    water += max(height - heightMap[i_][j_] , 0);
                    boundaryCells.push({max(height , heightMap[i_][j_]),{i_,j_}});
                    visited[i_][j_] = true;
                } 
            }
        }
        return water;
    }
};