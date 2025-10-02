63. Unique Paths II

approach 1:recursn 

time complexity:O(2^(n*m)) for each element we have 2 choices (right or down) but we starting from last so (left or up)
space complexity:O(n+m) path length 


class Solution {
    public:
        int solve(vector<vector<int>>& grid,int i,int j){
                // onstacle
                if(i>=0 && j>=0 && grid[i][j]==1) return 0;
                // base case
                if(i==0 && j==0 ){
                    // we havw reached our destination
                    // so we should count this path 
                    return 1;
                }
                if(i<0 || j<0) return 0;// index out of bound 
        
                int up =solve(grid,i-1,j);
                int left=solve(grid,i,j-1);
        
                return up+left;
            }
        int uniquePathsWithObstacles(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
    
            return solve(grid,m-1,n-1);
        }
    };

    approach 2:memoization  

    time complexity:O(n*m) because at max each cell can be called for once 
    space complexity:O((n-1)+(m-1))+o(n*m) path length+recusn stack space 

    class Solution {
        public:
            int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
                    // onstacle
                    if(i>=0 && j>=0 && grid[i][j]==1) return 0;
                    // base case
                    if(i==0 && j==0 ){
                        // we havw reached our destination
                        // so we should count this path 
                        return 1;
                    }
                    if(i<0 || j<0) return 0;// index out of bound 
        
                    if(dp[i][j]!=-1) return dp[i][j];
                    
                    int up =solve(grid,i-1,j,dp);
                    int left=solve(grid,i,j-1,dp);
            
                    return dp[i][j]=up+left;
                }
            int uniquePathsWithObstacles(vector<vector<int>>& grid) {
                int m=grid.size();
                int n=grid[0].size();
                vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
                return solve(grid,m-1,n-1,dp);
            }
        };

approach 3:tabulation  

time complexity:O(n*m) because at max each cell can be called for once 
space complexity:O(n-1)+(m-1)) no recursn stack space  
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>>dp(m,vector<int>(n,0));
           
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if( grid[i][j]==1){
                        dp[i][j]=0;
                    }else if(i==0 &&  j==0){
                         dp[i][j]=1;
                    }else{
                        int up=0;
                        int left=0;
                        if(i>0) up=dp[i-1][j];
                        if(j>0) left=dp[i][j-1];
                        dp[i][j]=up+left;
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };

    approach 4:space optimization  

    time complexity:O(n*m) because at max each cell can be called for once 
    space complexity:O(1)

    class Solution {
        public:
            int uniquePathsWithObstacles(vector<vector<int>>& grid) {
                int m=grid.size();
                int n=grid[0].size();
                vector<int>prev(n,0);
               
                for(int i=0;i<m;i++){
                    vector<int>curr(n,0);
                    for(int j=0;j<n;j++){
                        if( grid[i][j]==1){
                            curr[j]=0;
                        }else if(i==0 &&  j==0){
                             curr[j]=1;
                        }else{
                            int up=0;
                            int left=0;
                            if(i>0) up=prev[j];
                            if(j>0) left=curr[j-1];
                            curr[j]=up+left;
                        }
                    }
                    prev=curr;
                }
                return prev[n-1];
            }
        };
