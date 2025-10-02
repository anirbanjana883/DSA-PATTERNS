Check if there exists a subsequence with sum K

class Solution {
public:
    int target,size;
    int sum=0;
    bool helper(int i,vector<int>& arr,vector<bool>& dp){
        if(sum>target) return false;
        if(sum==target) return true;
        
        if(i>=size){
            return false;
        }
        
        bool res1=helper(i+1,arr,dp);
        if(res1) return dp[i]=true;
        
        sum+=arr[i];
        bool res2=helper(i+1,arr,dp);
        sum-=arr[i];
        if(res2) return dp[i]=true;
        
        return dp[i]=false;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        target=k;size=n;
        vector<bool>dp(n,false);
        return helper(0,arr,dp);
    }
};