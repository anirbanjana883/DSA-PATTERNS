673. Number of Longest Increasing Subsequence

please do a dry run seeing striver vedio


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1),count(n,1); // since eevry one is have 1 len subsequence
        int lisLength=0;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev] && dp[i] < 1 + dp[prev]) {
                    // inherit the count
                    dp[i] = 1 + dp[prev];
                    count[i]=count[prev];
                }else if (nums[i] > nums[prev] && dp[i] == 1 + dp[prev]){
                    //  i got someone as same length so increase the count  
                    count[i]+=count[prev];
                }
            }
            lisLength=max(lisLength,dp[i]);
        }
        int noOfLIS=0;
        for(int i=0;i<n;i++){
            if(dp[i]==lisLength) noOfLIS+=count[i];
        }
        return noOfLIS;
    }
};