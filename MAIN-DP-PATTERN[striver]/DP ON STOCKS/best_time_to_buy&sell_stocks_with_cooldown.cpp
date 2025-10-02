309. Best Time to Buy and Sell Stock with Cooldown

you can not buy stocks just after the next day of selling 
approach 1: recursn

time complexity : o(2^n)
space complexity : o(n)

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int buy,vector<vector<int>>dp){
            if(idx>=n) return 0; // because we going idx+2 that may cause out of bound
            if(dp[idx][buy]!=-1) return dp[idx][buy];
            int profit=0;
            if(buy){
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,0,dp),
                                    0+findMaxProfit(prices,idx+1,1,dp));
            }else{
                // can not buy the stock immediately next day so  idx+2
                profit=max(prices[idx]+findMaxProfit(prices,idx+2,1,dp),
                                    0+findMaxProfit(prices,idx+1,0,dp));
            }
            return dp[idx][buy]=profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            vector<vector<int>>dp(n,vector<int>(2,-1));
            return findMaxProfit(prices,0,1,dp);
        }
    };

approach 1: memoization 

time complexity : o(n*2)
space complexity : o(n*2)+(n) dp table + recursn stack  

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int buy,vector<vector<int>>&dp){
            if(idx>=n) return 0; // because we going idx+2 that may cause out of bound
            if(dp[idx][buy]!=-1) return dp[idx][buy];
            int profit=0;
            if(buy){
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,0,dp),
                                    0+findMaxProfit(prices,idx+1,1,dp));
            }else{
                profit=max(prices[idx]+findMaxProfit(prices,idx+2,1,dp),
                                    0+findMaxProfit(prices,idx+1,0,dp));
            }
            return dp[idx][buy]=profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            vector<vector<int>>dp(n,vector<int>(2,-1));
            return findMaxProfit(prices,0,1,dp);
        }
    };

approach 1: tabulation

time complexity : o(n*2)
space complexity : o(n*2) no recursn stack space 

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>dp(n+2,vector<int>(2,0));
            // since veerything is zero in the dp 
            // table so no need to erite base case seperately
            for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[idx]+dp[idx+1][0],
                                            0+dp[idx+1][1]);
                    }else{
                        profit=max(prices[idx]+dp[idx+2][1],
                                            0+dp[idx+1][0]);
                    }
                    dp[idx][buy]=profit;
                }
            }
            return dp[0][1];
        }
    };
approach 1: space optimization

time complexity : o(n*2)
space complexity : o(1)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int>curr(2,0);
            vector<int>next1(2,0);
            vector<int>next2(2,0);
            // since veerything is zero in the dp 
            // table so no need to erite base case seperately
            for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[idx]+next1[0],
                                            0+next1[1]);
                    }else{
                        profit=max(prices[idx]+next2[1],
                                            0+next1[0]);
                    }
                    curr[buy]=profit;
                }
                next2=next1;
                next1=curr;
            }
            return curr[1];
        }
    };