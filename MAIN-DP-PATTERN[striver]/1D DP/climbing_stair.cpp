70.Climbing Stairs 

recursive appproach : TLE

class Solution {
    public:
        int solve (int n){
            if(n==0){ // if there was only 1 stair
                return 1;
            }
            if(n==1){ // if there was only 2 stair
                return 1;
            }
    
            int left=solve(n-1);
            int right=solve(n-2);
            
            return left+right;
        }
        int climbStairs(int n) {
            return  solve(n);
        }
    };

memoization appproach :

class Solution {
    public:
        int solve (int n,vector<int>&dp){
            if(n==0){ // if there was only 1 stair
                return 1;
            }
            if(n==1){ // if there was only 2 stair
                return 1;
            }
    
            if(dp[n]!=-1){
                return dp[n];
            }
            
            return dp[n]=solve(n-1,dp)+solve(n-2,dp);
        }
        int climbStairs(int n) {
            vector<int>dp(n+1,-1);
            return  solve(n,dp);
        }
    };

    tabulation approach:

    class Solution {
        public:
            vector<int>dp;
            int solve(int n){
                dp[0]=1;
                dp[1]=1;
        
                for(int i=2;i<=n;i++){
                    dp[i]=dp[i-1]+dp[i-2];
                }
                return dp[n];
            }
            int climbStairs(int n) {
                dp.resize(n+1,-1);
                return solve(n);
            }
        };