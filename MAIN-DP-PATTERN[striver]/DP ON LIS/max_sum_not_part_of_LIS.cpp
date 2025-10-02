Maximum sum of elements not part of LIS

class Solution {
public:
    // time o (n ^2)
    // space o (n)
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        vector<int> dp(n, 1); // dp[i] = length of LIS ending at i
        vector<int> dpMinSum(n); // dpMinSum[i] = min sum of LIS ending at i with length dp[i]
        
        // Initialize dpMinSum with arr values
        for (int i = 0; i < n; i++) {
            dpMinSum[i] = arr[i];
        }
        
        int mxLis = 1; // maximum LIS length found so far
        int mnLisSum = arr[0]; // min sum for LIS with length mxLis
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        dpMinSum[i] = dpMinSum[j] + arr[i];
                    } else if (dp[j] + 1 == dp[i]) {
                        dpMinSum[i] = min(dpMinSum[i], dpMinSum[j] + arr[i]);
                    }
                }
            }
            
            // Update mxLis and mnLisSum after processing i
            if (dp[i] > mxLis) {
                mxLis = dp[i];
                mnLisSum = dpMinSum[i];
            } else if (dp[i] == mxLis) {
                mnLisSum = min(mnLisSum, dpMinSum[i]);
            }
        }
        
        return totalSum - mnLisSum;
    }
};