312. Burst Balloons

after inserting 1 at first and last 

nums = [1, 3, 1, 5, 8, 1]
           ^        ^
        index 1   index n (which is 4)


approach 1:recursn 
t.c - o(2^n) exponential
s.c - o(n)

class Solution {
public:
    int findMaxCost(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        int maxi=INT_MIN;
        for(int ind=i;ind<=j;ind++){
            int cost=( nums[i-1] * nums[ind] * nums[j+1] )+
                findMaxCost( i,ind-1,nums )+findMaxCost( ind+1,j,nums );
            maxi=max(maxi,cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return findMaxCost(1,n,nums);
    }
};

approach 2:memoization 
t.c - o(n*n) 
s.c - o(n*n)+o(n)

class Solution {
public:
    int findMaxCost(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        int maxi=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int ind=i;ind<=j;ind++){
            int cost=( nums[i-1] * nums[ind] * nums[j+1] )+
                findMaxCost( i,ind-1,nums,dp )+findMaxCost( ind+1,j,nums,dp );
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return findMaxCost(1,n,nums,dp);
    }
};

approach 2:tabulation 
t.c - o(n*n*n) 
s.c - o(n*n)


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int ind=i;ind<=j;ind++){
                    int cost=( nums[i-1] * nums[ind] * nums[j+1] )+
                        dp[i][ind-1]+dp[ind+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};