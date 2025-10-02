Minimum sum partition [gfg]
watch explanation of striver to see how dp table works here
the last row is crucial for commenting wheather the target is achivable or not  

verialtion of subset sum equals to k::

approach 1:memoization  

time complexity:O(n*sum) 
Space Complexity = O(n * totalSum)  // from DP table
                + O(n)              // call stack
                = O(n * totalSum)

bool subsetSum(vector<int>& arr, int idx, int sum, vector<vector<int>>& dp) {
    if (sum == 0) return true;
    if (idx == 0) return arr[0] == sum;
    if (dp[idx][sum] != -1) return dp[idx][sum];

    int exclude = subsetSum(arr, idx - 1, sum, dp);
    int include = false;
    if (arr[idx] <= sum) {
        include = subsetSum(arr, idx - 1, sum - arr[idx], dp);
    }
    return dp[idx][sum] = include || exclude;
}

int minDifference(vector<int>& arr) {
    int totalSum = 0;
    int n = arr.size();
    for (auto& ani : arr) {
        totalSum += ani;
    }

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));

    // Fill all dp[n-1][i] entries by calling subsetSum for each i
    for (int i = 0; i <= totalSum / 2; i++) {
        subsetSum(arr, n - 1, i, dp);
    }

    int ans = 1e9;
    for (int i = 0; i <= totalSum / 2; i++) {
        if (dp[n - 1][i] == true) {
            ans = min(ans, abs(totalSum - 2 * i));
        }
    }
    return ans;
}


approach 2:tabulation  

time complexity:O(n*sum) 
space complexity:O(n*sum)


public:
bool SubsetSum(vector<int>& arr, int sum,vector<vector<bool>>&dp) {
      int n=arr.size();
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
int minDifference(vector<int>& arr) {
    int totalSum=0;
    int n=arr.size();
    for(auto &ani:arr){
        totalSum+=ani;
    }
    vector<vector<bool>>dp(n+1,vector<bool>(totalSum+1,0));
    SubsetSum(arr,totalSum,dp);
    // just the last row of the dp matrix needed
    int ans=1e9;
    for(int i=0;i<=totalSum/2;i++){
        if(dp[n-1][i]==true){
            ans=min(ans,abs(totalSum-2*i));
        }
    }
    return ans;
}
};


approach 4:space optimization  

time complexity:O(n*sum) 
space complexity:O(1)


class Solution {
    public:
      bool SubsetSum(vector<int>& arr, int sum,vector<bool>&prev,vector<bool>&curr) {
            int n=arr.size();
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
      int minDifference(vector<int>& arr) {
          int totalSum=0;
          int n=arr.size();
          for(auto &ani:arr){
              totalSum+=ani;
          }
          vector<bool>prev(totalSum+1,false),curr(totalSum+1,false);
          SubsetSum(arr,totalSum,prev,curr);
          // just the last row of the dp matrix needed
          int ans=1e9;
          for(int i=0;i<=totalSum/2;i++){
              if(prev[i]==true){
                  ans=min(ans,abs(totalSum-2*i));
              }
          }
          return ans;
      }
  };
  