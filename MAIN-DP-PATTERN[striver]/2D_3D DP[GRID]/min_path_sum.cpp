64. Minimum Path Sum

approach 1: recursn 

time complexity is O(2^(m+n))
space complexity is O(m+n)

class Solution {
    public:
        int solve(vector<vector<int>>& grid,int i,int j){
            if(i==0 && j==0) return grid[i][j];
            if(i<0 || j<0) return 1e9; // so that this path is rejected automaticly
            int up=grid[i][j]+solve(grid,i-1,j);
            int left=grid[i][j]+solve(grid,i,j-1);
    
            return min(up,left);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            return solve(grid,m-1,n-1);
        }
};

approach 2: memoization 

time complexity is O((m*n))
space complexity is O(m*n)+O(m+n) dp array+stack place 

class Solution {
    public:
        int solve(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
            if(i==0 && j==0) return grid[i][j];
            if(i<0 || j<0) return 1e9; // so that this path is rejected automatic
            
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int up=grid[i][j]+solve(grid,i-1,j,dp);
            int left=grid[i][j]+solve(grid,i,j-1,dp);
    
            return dp[i][j]=min(up,left);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
            return solve(grid,m-1,n-1,dp);
        }
};

approach 3: tabulation

time complexity is O((m*n))
space complexity is O(m*n) dp array

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>>dp(m,vector<int>(n,0));
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 && j==0)  dp[i][j]=grid[i][j];
    
                    else{
                        int up=1e9;
                        int left=1e9;
    
                        if(i>0) up=grid[i][j]+dp[i-1][j];
                        if(j>0) left=grid[i][j]+dp[i][j-1];
    
                        dp[i][j]=min(up,left);
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };

approach 3: space optimisation 

time complexity is O((n))
space complexity is O(1) dp array

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();
            vector<int>prev(n,0);
    
            for(int i=0;i<m;i++){
                vector<int>curr(n,0);
                for(int j=0;j<n;j++){
                    if(i==0 && j==0)  curr[j]=grid[i][j];
    
                    else{
                        int up=1e9;
                        int left=1e9;
    
                        if(i>0) up=grid[i][j]+prev[j];
                        if(j>0) left=grid[i][j]+curr[j-1];
    
                        curr[j]=min(up,left);
                    }
                }
                prev=curr;
            }
            return prev[n-1];
        }
};