980. Unique Paths III

in the question it is asked to cover all the non 
obstacle Paths

Time Complexity: O(4^(M*N))

Space Complexity: O(M*N) [recursn stack space]

class Solution {
public:
    int totalNonObstacle;
    int n,m;
    int result;
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    void backT(vector<vector<int>>& grid,int count,int i,int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1) return;
        // we reached to the end
        if(grid[i][j]==2){
            if(count == totalNonObstacle){
                result++;
                return ;
            }
        }
        // mark visited
        int temp=grid[i][j];
        grid[i][j]=-1;
        // explore
        for(auto &dir:direction){
            int i_=dir[0]+i;
            int j_=dir[1]+j;
            backT(grid,count+1,i_,j_);
        }
        // mark unvisited
        grid[i][j]=temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int s_row_idx=0;
        int s_col_idx=0;
        result=0;
        totalNonObstacle=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                     s_row_idx=i;
                     s_col_idx=j;
                }else if(grid[i][j]==0){
                    totalNonObstacle ++;
                }
            }
        }
        totalNonObstacle += 1; // because start is also non obstacle
        backT(grid,0,s_row_idx,s_col_idx);
        return result;
    }
};