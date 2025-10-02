Longest Bitonic subsequence

example : 

1 11 2 10 4 5 2 1

Bitonic subsequence { 1 2 10 4 2 1 }
                    { 1 2 10 5 2 1 }
                    { 1 2 4 5 }


if (nums[i] > nums[prev]) {
    dp[i] = max(dp[i], 1 + dp[prev]);
}

here dp[i] signifies that the longest increasing subsequence till index idx
so we will see the array from right and left side 

arr     [1 11 2 10 4 5 2 1]
dp1     [1 2  3  3 3 3 2 1]
dp2     [1 5  1  4 3 3 2 1]
bitonic [1 6  3  6 5 6 3 1]  dp1[i]+dp2[i]-1

so length of bitonic is 6

 this code is correct if A strictly increasing or a strictly decreasing sequence should  be considered as a bitonic sequence

class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n, 1); // LIS ending at i
        vector<int> dp2(n, 1); // LDS starting at i

        // Compute LIS
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp1[i] = max(dp1[i], 1 + dp1[prev]);
                }
            }
        }

        // Compute LDS
        for (int i = n - 1; i >= 0; i--) {
            for (int next = i + 1; next < n; next++) {
                if (nums[i] > nums[next]) {
                    dp2[i] = max(dp2[i], 1 + dp2[next]);
                }
            }
        }

        // Compute maximum of dp1[i] + dp2[i] - 1
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }

        return maxi;
    }
};

but if A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence
this is the gfg question ,,,,,,,,,,

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1); // LIS ending at i
        vector<int> dp2(n, 1); // LDS starting at i
    
        // Compute LIS
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp1[i] = max(dp1[i], 1 + dp1[prev]);
                }
            }
        }
    
        // Compute LDS
        for (int i = n - 1; i >= 0; i--) {
            for (int next = i + 1; next < n; next++) {
                if (nums[i] > nums[next]) {
                    dp2[i] = max(dp2[i], 1 + dp2[next]);
                }
            }
        }
    
        // Compute max bitonic length with both increasing and decreasing
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
    
        return maxi;
}
};


