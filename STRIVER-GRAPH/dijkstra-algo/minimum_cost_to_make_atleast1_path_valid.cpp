1368. Minimum Cost to Make at Least One Valid Path in a Grid  {hard}

https://youtu.be/NS3C4W_jJJM?si=aLvVJLhQSSEPRLtz

approach 1:
backtracking--->
trying all the path and checking min Cost 

class Solution {
public:
int m,n;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int back_track(int i,int j,vector<vector<int>>& grid, vector<vector<bool>>&visited,int cost){
        // if we reach the last of the path then we found the valod path 
        if(i==m-1 && j==n-1) return cost;
        // else mark the cell as visited
        visited[i][j]=true;
        // explore all the ather path 
        // we will do simple dfs
        int minCost=INT_MAX;
        // we are taking help of direction array here
        for(int dir_i=0;dir_i<=3;dir_i++){
            int i_=i+dir[dir_i][0];
            int j_=j+dir[dir_i][1];
            // first check if going to i_ and j_ is valid move or not 
            // if it is a valid move then if the direction in grid 
            // and dir vector is same or not is same then no cost will be be
            // added atherwise cost will require 
            if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                int nextCost=cost+((grid[i][j]-1 != dir_i)?1:0);
                minCost=min(minCost,back_track(i_,j_,grid,visited,nextCost));
            }
        }
        // when one path is being visited then during returning mark 
        // the path as unvisited
        visited[i][j]=false;
        return minCost;        
    }
    int minCost(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        // since we are doing backtracking so we 
        // need a visited array 
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        return back_track(0,0,grid,visited,0);
    }
};

approach 2

class Solution {
public:
    // we will use dijkstra algorithm here
    // time complexity O(M*N*log(M*N))
    // space complexity O(M*N)
    // direction vector
    //                     {right, left,  down,   up}
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // we will define a priority queue
        // {distance , cell }
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        result[0][0] = 0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();  // log(M*N)

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            for (int dir_i = 0; dir_i < 4; dir_i++) {
                int i_ = i + dir[dir_i][0];
                int j_ = j + dir[dir_i][1];
                // first check if going to i_ and j_ is valid move or not
                // if it is a valid move then if the direction in grid
                // and dir vector is same or not is same then no cost will be be
                // added atherwise cost will require
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n 
                    ) {
                    int dirCost = ((grid[i][j] - 1 != dir_i) ? 1 : 0);
                    int newCost = currCost + dirCost;
                    if (newCost < result[i_][j_]) {
                        result[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};