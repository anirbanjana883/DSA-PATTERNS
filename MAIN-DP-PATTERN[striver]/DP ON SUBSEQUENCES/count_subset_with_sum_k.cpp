Perfect Sum Problem [gfg]

approach 1: recursn 
time complexity o(2^n)
space complexoty o(n)

class Solution {
    public:
      int countSubsequesnce(vector<int>& nums,int idx,int target){
          if(idx==0){
              // if one element and it is zero so if we take it or not take
              // in both the cases there will be no change
              if(target==0 && nums[0]==0) return 2;
              if(target==0 || target==nums[0]) return 1;
              return 0;
          }
          int not_pick=countSubsequesnce(nums,idx-1,target);
          int pick=0;
          if(nums[idx]<=target){
              pick=countSubsequesnce(nums,idx-1,target-nums[idx]);
          }
          return pick+not_pick;
      }
      int perfectSum(vector<int>& nums, int target) {
           int n=nums.size();
          return countSubsequesnce(nums,n-1,target); 
      }
  };
  

approach 1: memoization 
time complexity o(n*target)
space complexoty o(n*target)+o(n)


class Solution {
    public:
      int countSubsequence(vector<int>& nums, int idx, int target,vector<vector<int>>&dp){
          if(idx==0){
              // if one element and it is zero so if we take it or not take
              // in both the cases there will be no change
              if(target==0 && nums[0]==0) return 2;
              if(target==0 || target==nums[0]) return 1;
              return 0;
          }
          if(dp[idx][target]!=-1) return dp[idx][target];
          int not_pick = countSubsequence(nums, idx - 1, target,dp);
          int pick = 0;
          if (nums[idx] <= target) {
              pick = countSubsequence(nums, idx - 1, target - nums[idx],dp);
          }
          return dp[idx][target]=pick + not_pick;
      }
  
      int perfectSum(vector<int>& nums, int target) {
          int n = nums.size();
          vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
          return countSubsequence(nums, n - 1, target,dp); 
      }
  };
  
  

approach 1: tabulation
time complexity o(n*target)
space complexoty o(n*target)


class Solution {
    public:
      int perfectSum(vector<int>& nums, int target) {
          int n = nums.size();
          vector<vector<int>>dp(n+1,vector<int>(target+1,0));
          if (nums[0] == 0) {
              dp[0][0] = 2; // pick or not pick
          } else {
              dp[0][0] = 1; // not pick
              if (nums[0] <= target)
                  dp[0][nums[0]] = 1; // pick
          }
          for(int idx=1;idx<n;idx++){
              for(int t=0;t<=target;t++){
                  int not_pick = dp[idx - 1][t];
                  int pick = 0;
                  if (nums[idx] <= t) {
                      pick = dp[idx - 1][t - nums[idx]];
                  }
                  dp[idx][t]=pick+not_pick;
              }
          }
          return dp[n-1][target];
      }
  };

approach 1: space optimisation 
time complexity o(n*target)
space complexoty o(target)

class Solution {
    public:
      int perfectSum(vector<int>& nums, int target) {
      int n = nums.size();
      vector<int> prev(target + 1, 0);
      vector<int> curr(target + 1, 0);
      
      prev[0] = curr[0] = 1;
  
      for (int idx = 0; idx < n; idx++) {  
          for (int t = 0; t <= target; t++) {
              int not_pick = prev[t];
              int pick = 0;
              if (nums[idx] <= t) {
                  pick = prev[t - nums[idx]];
              }
              curr[t] = pick + not_pick;
          }
          prev = curr;
      }
  
      return curr[target];
      }
  }