Maximum path sum in matrix  gfg

$$$$$$$$$$$
this is a problrm of multiple starting and multiple ending point **
$$$$$$$$$$$ 

(r+1, c-1) — move diagonally to the left. (recursn right)
(r+1, c) — move directly down. (recursn up)
(r+1, c+1) — move diagonally to the right. (recursn left)

try out all the possible path ====> recursn ..

approach 1: recursn 

time complexity is O(3^(nm))
space complexity is O(n) recursn stack space for storing the path length

class Solution {
    public:
      int solve(int i,int j,vector<vector<int>>& mat){
          // if the path is not reachable then return a very min value 
          if(j<0 || j>=mat[0].size()) return -1e8;
          if(i==0 ) return mat[0][j];
          
          int up = mat[i][j]+solve(i-1,j,mat);
          int lDiag = mat[i][j]+solve(i-1,j-1,mat);
          int rDiag = mat[i][j]+solve(i-1,j+1,mat);
          
          return max(up,max(lDiag,rDiag));
      }
      int maximumPath(vector<vector<int>>& mat) {
          int n=mat.size();
          int m=mat[0].size();
          
          int maxi=-1e9;
          for(int j=0;j<m;j++){
              maxi=max(maxi,solve(n-1,j,mat));
          }
          return maxi;
      }
};

approach 2: memoization 

time complexity is O((m*n))
space complexity is O(m*n)+O(n) dp array+stack place 

class Solution {
    public:
      int solve(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&dp){
          // if the path is not reachable then return a very min value 
          if(j<0 || j>=mat[0].size()) return -1e8;
          if(i==0 ) return mat[0][j];
          
          if(dp[i][j]!=-1){
              return dp[i][j];
          }
          
          int up = mat[i][j]+solve(i-1,j,mat,dp);
          int lDiag = mat[i][j]+solve(i-1,j-1,mat,dp);
          int rDiag = mat[i][j]+solve(i-1,j+1,mat,dp);
          
          return dp[i][j]=max(up,max(lDiag,rDiag));
      }
      int maximumPath(vector<vector<int>>& mat) {
          int n=mat.size();
          int m=mat[0].size();
          vector<vector<int>>dp(n,vector<int>(m,-1));
          
          int maxi=-1e9;
          for(int j=0;j<m;j++){
              maxi=max(maxi,solve(n-1,j,mat,dp));
          }
          return maxi;
      }
  };
  

approach 3: tabulation

time complexity is O((m*n))
space complexity is O(n) dp array


class Solution {
    public:
      int maximumPath(vector<vector<int>>& mat) {
          int n=mat.size();
          int m=mat[0].size();
          vector<vector<int>>dp(n,vector<int>(m,0));
          
          // the last column is for base case 
          for(int j=0;j<m;j++){
              dp[0][j]=mat[0][j];
          }
          
          for(int i=1;i<n;i++){
              for(int j=0;j<m;j++){
                int up = mat[i][j]+dp[i-1][j];
                
                int lDiag = mat[i][j];
                if(j-1>=0) lDiag+=dp[i-1][j-1];
                else lDiag+=-1e8; // omit the path
                
                int rDiag = mat[i][j];
                if(j+1<m) rDiag+=dp[i-1][j+1];
                else rDiag+=-1e8; // omit the path
                
                dp[i][j]=max(up,max(lDiag,rDiag));
              }
          }
          int maxi=-1e9;
          for(int j=0;j<m;j++){
              maxi=max(maxi,dp[n-1][j]);
          }
          return maxi;
      }
  };

approach 3: space optimisation 

time complexity is O((n))
space complexity is O(n) just the prev and curr vector


class Solution {
    public:
      int maximumPath(vector<vector<int>>& mat) {
          int n=mat.size();
          int m=mat[0].size();
          vector<int>prev(m,0);
          
          // the last column is for base case 
          for(int j=0;j<m;j++){
              prev[j]=mat[0][j];
          }
          
          for(int i=1;i<n;i++){
              vector<int>curr(m,0);
              for(int j=0;j<m;j++){
                int up = mat[i][j]+prev[j];
                
                int lDiag = mat[i][j];
                if(j-1>=0) lDiag+=prev[j-1];
                else lDiag+=-1e8; // omit the path
                
                int rDiag = mat[i][j];
                if(j+1<m) rDiag+=prev[j+1];
                else rDiag+=-1e8; // omit the path
                
                curr[j]=max(up,max(lDiag,rDiag));
              }
              prev=curr;
          }
          int maxi=-1e9;
          for(int j=0;j<m;j++){
              maxi=max(maxi,prev[j]);
          }
          return maxi;
      }
  };