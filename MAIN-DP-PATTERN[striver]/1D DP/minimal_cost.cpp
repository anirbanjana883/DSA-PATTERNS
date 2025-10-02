Minimal Cost  [gfg]

approach 1: recursn 

t.c o(n*k)
s.c o(n) recursn stack space 
class Solution {
    public:
      int solve(vector<int>&arr,int idx,int k){
          if(idx==0) return 0;
          int min_cost=INT_MAX;
          for(int j=1;j<=k;j++){
              if(idx-j>=0) {
                 int temp= solve(arr,idx-j,k)+abs(arr[idx]-arr[idx-j]);
                 min_cost=min(min_cost,temp);
              }
              
          }
          return min_cost;
      }
      int minimizeCost(int k, vector<int>& arr) {
          // Code here
          int n=arr.size();
          return solve(arr,n-1,k);
      }
  };

approach 2: memoization

t.c o(n*k)
s.c o(n)+o(n) recursn stack space+memoization



class Solution {
    public:
      int solve(vector<int>&arr,int idx,int k,vector<int>&dp){
          if(idx==0) return 0;
          
          if(dp[idx]!=-1) return dp[idx];
          
          int min_cost=INT_MAX;
          for(int j=1;j<=k;j++){
              if(idx-j>=0) {
                 int temp= solve(arr,idx-j,k,dp)+abs(arr[idx]-arr[idx-j]);
                 min_cost=min(min_cost,temp);
              }
              
          }
          return dp[idx]=min_cost;
      }
      int minimizeCost(int k, vector<int>& arr) {
          // Code here
          int n=arr.size();
          vector<int>dp(n+1,-1);
          return solve(arr,n-1,k,dp);
      }
  };


  approach 3: tabulation 

  t.c o(n*k)
    s.c o(n) dp vector space
  class Solution {
    public:
      int minimizeCost(int k, vector<int>& arr) {
          // Code here
          int n=arr.size();
          vector<int>dp(n,0);
          
          for(int i=1;i<n;i++){
              int min_cost=INT_MAX;
              for(int j=1;j<=k;j++){
                  if(i-j>=0){
                      int temp=dp[i-j]+abs(arr[i]-arr[i-j]);
                      min_cost=min(min_cost,temp);
                  }
              }
              dp[i]=min_cost;
          }
          return dp[n-1];
      }
  };