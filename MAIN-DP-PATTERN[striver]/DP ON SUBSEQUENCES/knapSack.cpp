0 - 1 Knapsack Problem

approach 1:recursn 

time complexity:O(2^n) 
space complexity:O(n) auxiliary recursn stack place .. 

class Solution {
    public:
      int n;
      int solve(int W, vector<int> &val, vector<int> &wt,int idx){
          // base case
          if(idx==0){
              if(wt[idx]<=W) return val[idx];
              return 0;
          }
          int not_take=0+solve(W,val,wt,idx-1);
          int take=INT_MIN;
          if(wt[idx]<=W){
              take=val[idx]+solve(W-wt[idx],val,wt,idx-1);
          }
          return max(not_take,take);
      }
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          n=val.size();
          return solve(W,val,wt,n-1);
      }
  };

approach 1:memoization 

time complexity:O(n*W) 
space complexity:O(n)+O(n*W) auxiliary recursn stack place .. 

class Solution {
    public:
      int n;
      int solve(int W, vector<int> &val, vector<int> &wt,int idx,vector<vector<int>>&dp){
          // base case
          if(idx==0){
              if(wt[idx]<=W) return val[idx];
              return 0;
          }
          if(dp[idx][W]!=-1) return dp[idx][W];
          int not_take=0+solve(W,val,wt,idx-1,dp);
          int take=INT_MIN;
          if(wt[idx]<=W){
              take=val[idx]+solve(W-wt[idx],val,wt,idx-1,dp);
          }
          return dp[idx][W]=max(not_take,take);
      }
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          n=val.size();
          vector<vector<int>>dp(n,vector<int>(W+1,-1));
          return solve(W,val,wt,n-1,dp);
      }
  };

approach 3: Tabulation 

time complexity:O(n*W) 
space complexity:O(n*W)

class Solution {
    public:
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n=val.size();
          vector<vector<int>>dp(n+1,vector<int>(W+1,0));
          for(int weight=0;weight<=W;weight++){
              dp[0][weight] = (wt[0] <= weight) ? val[0] : 0;
          }
          for(int idx=1;idx<n;idx++){
              for(int weight=0;weight<=W;weight++){
                  int not_take=dp[idx-1][weight];
                  int take=INT_MIN;
                  if(wt[idx]<=weight){
                      take=val[idx]+dp[idx-1][weight-wt[idx]];
                  }
                  dp[idx][weight]=max(take,not_take);
              }
          }
          return dp[n-1][W];
      }
  };
  

approach 1:space optimisation 

time complexity:O(n*W) 
space complexity:O(W) auxiliary recursn stack place .. 

class Solution {
    public:
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          int n=val.size();
          vector<int>prev(W+1,0);
          vector<int>curr(W+1,0);
          for (int weight = 0; weight <= W; weight++) {
              prev[weight] = (wt[0] <= weight) ? val[0] : 0;
          }
          for(int idx=1;idx<n;idx++){
              for(int weight=0;weight<=W;weight++){
                  int not_take=prev[weight];
                  int take=INT_MIN;
                  if(wt[idx]<=weight){
                      take=val[idx]+prev[weight-wt[idx]];
                  }
                  curr[weight]=max(take,not_take);
              }
              prev=curr;
          }
          return prev[W];
      }
  };
  