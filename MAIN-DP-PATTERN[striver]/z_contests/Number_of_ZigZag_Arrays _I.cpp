3699. Number of ZigZag Arrays I

note that in leetcode during contest always deckl=lear the dp array 
outside he class atherwise it will give tle

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MOD = 1e9 + 7;
        int k = r - l + 1; // number of distinct values
        
        // dp[i][0][x] - sequences of length i ending with value x, next should be down
        // dp[i][1][x] - sequences of length i ending with value x, next should be up
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        
        // Initialize: for length 1, any value is valid
        for (int x = 0; x < k; x++) {
            dp[1][0][x] = 1; // next should be down
            dp[1][1][x] = 1; // next should be up
        }
        
        for (int i = 2; i <= n; i++) {
            // Calculate prefix sums for optimization
            vector<long long> prefix0(k + 1, 0), prefix1(k + 1, 0);
            
            for (int x = 0; x < k; x++) {
                prefix0[x + 1] = (prefix0[x] + dp[i - 1][0][x]) % MOD;
                prefix1[x + 1] = (prefix1[x] + dp[i - 1][1][x]) % MOD;
            }
            
            for (int x = 0; x < k; x++) {
                // Current value is l + x
                int current = l + x;
                
                // If next should be down (current > next), then previous should have been up (prev < current)
                // So for dp[i][0][x], we need all sequences of length i-1 ending with values < current
                // where the next comparison was "up"
                if (current > l) {
                    // Find the index where values become >= current
                    int idx = current - l;
                    dp[i][0][x] = (dp[i][0][x] + prefix1[idx]) % MOD;
                }
                
                // If next should be up (current < next), then previous should have been down (prev > current)
                // So for dp[i][1][x], we need all sequences of length i-1 ending with values > current
                // where the next comparison was "down"
                if (current < r) {
                    // Values from current+1 to r
                    int startIdx = current - l + 1;
                    dp[i][1][x] = (dp[i][1][x] + prefix0[k] - prefix0[startIdx] + MOD) % MOD;
                }
            }
        }
        
        // Sum all valid sequences of length n
        long long result = 0;
        for (int x = 0; x < k; x++) {
            result = (result + dp[n][0][x] + dp[n][1][x]) % MOD;
        }
        
        return result;
    }
};