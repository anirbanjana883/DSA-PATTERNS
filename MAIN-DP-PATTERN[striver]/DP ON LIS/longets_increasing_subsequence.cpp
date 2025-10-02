300. Longest Increasing Subsequence

extreme broute force approach : generate all the sunsequence and check t.c o(2^n) ==> TLE

approach 2: recursn 
time complexity:O(2^n)
space complexity:o(N) auxiliary space (because same coin can be used many time ) so at worst this can be s.c

significance of function(idx,prevIdx) => length of longest increasing subsequence ending at idx and prevIdx is the last element in the subsequence

class Solution {
public:
    int solve(vector<int>& nums,int n,int idx,int prevIdx){
        // base case 
        if(idx==n) return 0;
        // explore all posibilities
        int len=0+solve(nums,n,idx+1,prevIdx); // not take
        if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
            len=max(len,1+solve(nums,n,idx+1,idx)); // take 
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,n,0,-1);
    }
};

approach 1:memoization 

time complexity:O(n*n) 
space complexity:O(N)+O(n*n) auxiliary recursn stack place .. 

class Solution {
public:
    int solve(vector<int>& nums,int n,int idx,int prevIdx,vector<vector<int>>&dp){
        // base case 
        if(idx==n) return 0;
        // coordinate shift require [prevIdx+1]
        if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];
        // explore all posibilities
        int len=0+solve(nums,n,idx+1,prevIdx,dp); // not take
        if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
            len=max(len,1+solve(nums,n,idx+1,idx,dp)); // take 
        }
        return dp[idx][prevIdx+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(nums,n,0,-1,dp);
    }
};

approach 3: Tabulation 

time complexity:O(n*n) 
space complexity:O(n*n)

tabulation 1:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // since in the dp table evry this is written as zero so no need 
        // so no need to write base case seperate
        for(int idx=n-1;idx>=0;idx--){
            // simce prevIdx can not be greater then idx
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                int len=0+dp[idx+1][prevIdx+1]; // not take
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
                    len=max(len,1+dp[idx+1][idx+1]); // take 
                }   
                dp[idx][prevIdx+1]=len;
            }
        }
        return dp[0][-1+1];
    }
};

tabulation 2: not very much intutive see striver lecture for rivision 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // since eevry one is have 1 len subsequence
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] > nums[prev]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi,
                       dp[i]); // t5his is finding the max amng all the dp table
        }
        return maxi;
    }
};

approach 1:space optimisation 

time complexity:O(n*N) 
space complexity:O(2*N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0),curr(n+1,0);
        // since in the dp table evry this is written as zero so no need 
        // so no need to write base case seperate
        for(int idx=n-1;idx>=0;idx--){
            // simce prevIdx can not be greater then idx
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                int len=0+next[prevIdx+1]; // not take
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
                    len=max(len,1+next[idx+1]); // take 
                }   
                curr[prevIdx+1]=len;
            }
            next=curr;
        }
        return next[-1+1];
    }
};

approach 1: more more space optimisation 

time complexity:O(n*N) 
space complexity:O(N)


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>next(n+1,0);
        // since in the dp table evry this is written as zero so no need 
        // so no need to write base case seperate
        for(int idx=n-1;idx>=0;idx--){
            // simce prevIdx can not be greater then idx
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                int len=0+next[prevIdx+1]; // not take
                if(prevIdx==-1 || nums[idx]>nums[prevIdx]){
                    len=max(len,1+next[idx+1]); // take 
                }   
                next[prevIdx+1]=len;
            }
        }
        return next[-1+1];
    }
};
