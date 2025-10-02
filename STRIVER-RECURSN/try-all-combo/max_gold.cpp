1219. Path with Maximum Gold

class Solution {
public:
    int answer=0;
    int m,n;
    vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
    void DFS(vector<vector<int>>& grid,int i,int j,int res){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            answer=max(answer,res);
            return ;
        }
        int temp=grid[i][j];
        res+=grid[i][j];
        grid[i][j]=0;  // mark the cell as visited
        for(auto &dir:direction){
            int i_=dir[0]+i;
            int j_=dir[1]+j;
            DFS(grid,i_,j_,res);
        }
        grid[i][j]=temp; // resetting the value 
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        // You can start and stop collecting gold from any position in the grid
        // that has some gold.
         m=grid.size();
         n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    DFS(grid,i,j,0);
                }
            }
        }
        return answer;
    }
};