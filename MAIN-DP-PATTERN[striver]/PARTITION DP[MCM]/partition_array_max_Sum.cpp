1043. Partition Array for Maximum Sum

approach 1: recurnsn

time complexity o(k^n) exponenetial 
space complexity o(n) stack space 

class Solution {
public:
    // again a question of front partition
    int findMaxSum(vector<int>& arr, int ind, int n, int k) {
        if (ind == n)
            return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + findMaxSum(arr, j + 1, n, k);
            maxAns = max(maxAns, sum);
        }
        return maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return findMaxSum(arr, 0, n, k);
    }
};

approach 2: memoization 

time complexity o(n*k)
space complexity o(n)+o(n) stack space 

class Solution {
public:
    // again a question of front partition
    int findMaxSum(vector<int>& arr, int ind, int n, int k,vector<int>&dp) {
        if (ind == n)
            return 0;

        if(dp[ind]!=-1) return dp[ind];
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len * maxi + findMaxSum(arr, j + 1, n, k,dp);
            maxAns = max(maxAns, sum);
        }
        return dp[ind]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return findMaxSum(arr, 0, n, k,dp);
    }
};

approach 2: tabulation  

time complexity o(n*k)
space complexity o(n)  no auxiliary stack space 

class Solution {
public:
    // again a question of front partition
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
            for (int j = ind; j < min(n, ind + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j + 1];
                maxAns = max(maxAns, sum);
            }
            dp[ind]=maxAns;
        }
        return dp[0];
    }
};