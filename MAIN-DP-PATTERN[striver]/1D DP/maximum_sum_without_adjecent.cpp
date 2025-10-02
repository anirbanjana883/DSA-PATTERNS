Max Sum without Adjacents [gfg]

approach 1: recrsn 

time complexity o(2^n);
space  complexity o(n) recursn stack place 

class Solution {
    public:
      int solve(vector<int>&arr,int idx){
          if(idx==0) return arr[idx];
          if(idx<0) return 0;
          
          int pick=arr[idx]+solve(arr,idx-2);
          int not_pick=0 + solve(arr,idx-1);
          
          return max(pick,not_pick);
      }
      int findMaxSum(vector<int>& arr) {
          int n=arr.size();
          return solve(arr,n-1);
      }
  };

approach 1: memoization  

time complexity o(n);
space  complexity o(n)+o(n) recursn stack place + dp array  

class Solution {
    public:
      int solve(vector<int>&arr,int idx,vector<int>&dp){
          if(idx==0) return arr[idx];
          if(idx<0) return 0;
          if(dp[idx]!=-1) return dp[idx];
          
          int pick=arr[idx]+solve(arr,idx-2,dp);
          int not_pick=0 + solve(arr,idx-1,dp);
          
          return dp[idx]=max(pick,not_pick);
      }
      int findMaxSum(vector<int>& arr) {
          int n=arr.size();
          vector<int>dp(n+1,-1);
          return solve(arr,n-1,dp);
      }
  };

  approach 1: tabulation  

time complexity o(n);
space  complexity o(n);

class Solution {
    public:
      // calculate the maximum sum with out adjacent
      int findMaxSum(vector<int>& arr) {
         
         int n=arr.size();
         
         vector<int>dp(n,0);
          //   base case 
          dp[0]=arr[0];
          for(int idx=1;idx<n;idx++){
              int take = arr[idx];
              if(idx>1) { // to handle the index out of bound
                  take+=dp[idx-2];
              }
              
              int not_take=0+dp[idx-1];
              dp[idx]=max(take,not_take);
          }
          return dp[n-1];
      }
  };

  approach 4:space optimization 

  time complexity o(n);
space  complexity o(1);

  class Solution {
    public:
      // calculate the maximum sum with out adjacent
      int findMaxSum(vector<int>& arr) {
         
         int n=arr.size();
         
          int prev=arr[0];
          int prev2=0;
          
          for(int idx=1;idx<n;idx++){
              int take = arr[idx];
              if(idx>1) { // to handle the index out of bound
                  take+=prev2;
              }
              
              int not_take=0+prev;
              int curr=max(take,not_take);
              
              prev2=prev;
              prev=curr;
          }
          return prev;
        }
    };

    follow up question :  198. House Robber
                          213. House Robber II