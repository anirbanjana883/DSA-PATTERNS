 Frog Jump  [gfg]

 Input: heights[] = [20, 30, 40, 20] 
 Output: 20
 Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
 jump from stair 0 to 1: cost = |30-20| = 10
 jump from stair 1 to 3: cost = |20-30|  = 10
 Total Cost = 10 + 10 = 20

>> here we are trying all possible ways  => recursn
 and choosing the best one => DP


 remeber the steps ??
 1. express in terms of index
 2. do all stuff on the index
 3. take the minimum..

 f(n-1) -> signifies minimum  energy requires to reach n-1 th stair

 and the cost of jump is abs(a[ind]-a[ind-1]);

 approach 1: recursion

 time complexity : O(n)
 space complexity : O(1)

 class Solution {
    public:
      int solve(vector<int>&height,int n){
          if(n==0) return 0;
          
  
           int one_step = solve(height,n-1)+abs(height[n]-height[n-1]);
          
          // as we are moving two step backword
          int two_step=INT_MAX;
          if(n>1){
               two_step = solve(height,n-2)+abs(height[n]-height[n-2]);
          }
          return min(one_step,two_step);
      }
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          return solve(height,n-1);
      }
  };

  approach 2: memoization (top down)

  time complexity : O(n)
  space complexity : O(2*n) recursn stack space + memoization space

  class Solution {
    public:   
      int solve(vector<int>&height,int n,vector<int>&dp){
          if(n==0) return 0;
          
          if(dp[n]!=-1) return dp[n];
  
          int one_step = solve(height,n-1,dp)+abs(height[n]-height[n-1]);
          
          // as we are moving two step backword
          int two_step=INT_MAX;
          if(n>1){
               two_step = solve(height,n-2,dp)+abs(height[n]-height[n-2]);
          }
          return dp[n]=min(one_step,two_step);
      }
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          vector<int>dp(n+1,-1);
          return solve(height,n-1,dp);
      }
  };



  approach 3: tabulation (bottom up)

  time complexity : O(n)
  space complexity : O(n)

  class Solution {
    public:
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          vector<int>dp(n,0);
          
          // base3 case 
          dp[0]=0;
          for(int i=1;i<n;i++){
              int one_step=dp[i-1]+abs(height[i]-height[i-1]);
              
              int two_step=INT_MAX;
              if(i>1){
                   two_step=dp[i-2]+abs(height[i]-height[i-2]);
              }
              
              dp[i]=min(one_step,two_step);
          }
          return dp[n-1];
      }
  };

approach 4: space reduction 

 time complexity : O(n)
  space complexity : O(1)

  class Solution {
    public:
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          
          int prev=0;
          int prev2=0;
          
          for(int i=1;i<n;i++){
              int one_step=prev+abs(height[i]-height[i-1]);
              
              int two_step=INT_MAX;
              if(i>1){
                   two_step=prev2+abs(height[i]-height[i-2]);
              }
              
             int  curr=min(one_step,two_step);
              prev2=prev;
              prev=curr;
          }
           return prev;
      }
  };
  
  follow up question 

  2140. Solving Questions With Brainpower
  198. House Robber
  403. Frog Jump