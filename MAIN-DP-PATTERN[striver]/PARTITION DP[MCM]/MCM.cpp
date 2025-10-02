Matrix Chain Multiplication [gfg Hard]

approach 1: recurnsn

time complexity o(2^n)
space complexity o(n) stack space 

class Solution {
    public:
       int f(vector<int>& arr, int i, int j) {
      if (i == j) {
          return 0;
      }
      int mini = INT_MAX;
      for (int k = i; k <= j - 1; k++) {
          int ans = f(arr, i, k) + f(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
          mini = min(mini, ans);
      }
  
      return  mini;
  }
  
      int matrixMultiplication(vector<int> &arr) {
          int n = arr.size();
          int i = 1;
          int j = n - 1;
          return f(arr, i, j);
      }
  }; 

approach 2: memoization 

time complexity o(n^3)
space complexity o(n)+o(n^2) stack space 

class Solution {
    public:
       int f(vector<int>& arr, int i, int j, vector<vector<int>>& dp) {
      if (i == j) {
          return 0;
      }
      if (dp[i][j] != -1) {
          return dp[i][j];
      }
  
      int mini = INT_MAX;
      for (int k = i; k <= j - 1; k++) {
          int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
          mini = min(mini, ans);
      }
  
      return dp[i][j] = mini;
  }
  
      int matrixMultiplication(vector<int> &arr) {
          int n = arr.size();
          int i = 1;
          int j = n - 1;
  
          vector<vector<int>> dp(n, vector<int>(n, -1));
          return f(arr, i, j, dp);
      }
  };

approach 2: tabulation  

time complexity o(n^3)
space complexity o(n^2) 

class Solution {
public:
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    int i = 1;
    int j = n - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int i=0;i<n;i++){ /// this  can be ommited 
        dp[i][i]=0;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini = 1e9;
            for (int k = i; k <= j - 1; k++) {
                int ans = dp[i][k] + dp[k + 1][j]+ arr[i - 1] * arr[k] * arr[j];
                mini = min(mini, ans);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
    
}
};