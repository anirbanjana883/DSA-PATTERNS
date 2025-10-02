Subset Sum Problem [gfg]

approach 1:recursn 

time complexity:O(2^n) 
space complexity:O(n) auxiliary recursn stack place .. 

class Solution {
    public:
      bool solve(vector<int>& arr,int sum,int idx){
          if(sum==0) return true;
          if(idx==0) return arr[0]==sum;
          
          bool exclude=solve(arr,sum,idx-1);
          bool include=false;
          if(arr[idx]<=sum){
              include=solve(arr,sum-arr[idx],idx-1);
          }
          return include || exclude;
      }
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n=arr.size();
          return solve(arr,sum,n-1);
      }
  };

approach 2:memoization  

time complexity:O(n*sum) 
space complexity:O(n*sum)+o(n)

class Solution {
    public:
      bool solve(vector<int>& arr,int sum,int idx,vector<vector<int>>&dp){
          if(sum==0) return true;
          if(idx==0) return arr[0]==sum;
          if(dp[idx][sum]!=-1) {
              return dp[idx][sum];
          }
          bool exclude=solve(arr,sum,idx-1,dp);
          bool include=false;;
          if(arr[idx]<=sum){
              include=solve(arr,sum-arr[idx],idx-1,dp);
          }
          return dp[idx][sum]=include || exclude;
      }
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n=arr.size();
          vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
          return solve(arr,sum,n-1,dp);
      }
  };
approach 3:tabulation  

time complexity:O(n*sum) 
space complexity:O(n*sum)

class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here 
          int n=arr.size();
          vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
          
          // base case 
          for(int i=0;i<n;i++) dp[i][0]=true;
          dp[0][arr[0]]=true;
          
          for(int ind=1;ind<n;ind++){
              for(int target=1;target<=sum;target++){
                  bool exclude=dp[ind-1][target];
                  bool include=false;
                  if(arr[ind]<=target){
                      include=dp[ind-1][target-arr[ind]];
                  }
                  
                  dp[ind][target]=exclude || include;
              }
          }
          return dp[n-1][sum];
          
      }
  };

approach 4:space optimization  

time complexity:O(n*sum) 
space complexity:O(1)

class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here 
          int n=arr.size();
          vector<bool>prev(sum+1,false),curr(sum+1,false);
          prev[0]=curr[0]=true;
          prev[arr[0]]=true;
          for(int ind=1;ind<n;ind++){
              for(int target=1;target<=sum;target++){
                  bool exclude=prev[target];
                  bool include=false;
                  if(arr[ind]<=target){
                      include=prev[target-arr[ind]];
                  }
                  
                  curr[target]=exclude || include;
              }
              prev=curr;
          }
          return prev[sum];
          
      }
  };