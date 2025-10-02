122. Best Time to Buy and Sell Stock II

# can buy as many time as you can and sell as many time you can 
# but  may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time

approach 1: recursn

time complexity : o(2^n)
space complexity : o(n)

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int buy){
            if(idx==n) return 0; // no more stocks can be buyed
            int profit=0;
            if(buy){ // can buy stocks but can not sell
                // if buyed - money spend thats why negative
                profit= max(-prices[idx]+findMaxProfit(prices,idx+1,0),
                            0+findMaxProfit(prices,idx+1,1));
            }else{   // can not buy stocks but can sell
                profit= max(prices[idx]+findMaxProfit(prices,idx+1,1),
                            0+findMaxProfit(prices,idx+1,0));
            }
            return profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            /* 0 ->can not buy
               1 -> can buy  */
            return findMaxProfit(prices,0,1);
        }
    };

approach 1: memoization 

time complexity : o(n)
space complexity : o(2*n)+(n) dp table + recursn stack  

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int buy,vector<vector<int>>&dp){
            if(idx==n) return 0; // no more stocks can be buyed-
            if(dp[idx][buy]!=-1){
                return dp[idx][buy];
            }
            int profit=0;
            if(buy){ // can buy stocks but can not sell
                // if buyed - money spend thats why negative
                profit= max(-prices[idx]+findMaxProfit(prices,idx+1,0,dp),
                            0+findMaxProfit(prices,idx+1,1,dp));
            }else{   // can not buy stocks but can sell
                profit= max(prices[idx]+findMaxProfit(prices,idx+1,1,dp),
                            0+findMaxProfit(prices,idx+1,0,dp));
            }
            return dp[idx][buy]=profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            /* 0 ->can not buy
               1 -> can buy  */
            vector<vector<int>>dp(n,vector<int>(2,-1));
            return findMaxProfit(prices,0,1,dp);
        }
    };

approach 1: tabulation

time complexity : o(n)
space complexity : o(2*n) no recursn stack space 

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            /* 0 ->can not buy
               1 -> can buy  */
            vector<vector<int>>dp(n+1,vector<int>(2,0));
            // base case 
            // if(idx==n) return 0;
            dp[n][0]=dp[n][1]=0;
            for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy){ // can buy stocks but can not sell
                        // if buyed - money spend thats why negative
                        profit= max(-prices[idx]+dp[idx+1][0],
                                    0+dp[idx+1][1]);
                    }else{   // can not buy stocks but can sell
                        profit= max(prices[idx]+dp[idx+1][1],
                                    0+dp[idx+1][0]);
                    }
                    dp[idx][buy]=profit;
                }
            }
            return dp[0][1];
        }
    };

approach 1: space optimization

time complexity : o(n)
space complexity : o(2)=o(1)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            /* 0 ->can not buy
               1 -> can buy  */
            vector<int>next(2,0),curr(2,0);
            // base case 
            // if(idx==n) return 0;
            next[0]=next[1]=0;
            for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    int profit=0;
                    if(buy){ // can buy stocks but can not sell
                        // if buyed - money spend thats why negative
                        profit= max(-prices[idx]+next[0],
                                    0+next[1]);
                    }else{   // can not buy stocks but can sell
                        profit= max(prices[idx]+next[1],
                                    0+next[0]);
                    }
                    curr[buy]=profit;
                }
                next=curr;
            }
            return next[1];
        }
    };

approach 1: more optimisation using4 veriable 

for this watch striver explanation ->

time complexity : o(n)
space complexity : o(1)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            /* 0 ->can not buy
               1 -> can buy  */
            int nextBuy,nextNotBuy,currBuy,currNotBuy;   
            nextBuy=nextNotBuy=0; // base case
            for(int idx=n-1;idx>=0;idx--){
                currBuy= max(-prices[idx]+nextNotBuy,
                            0+nextBuy);
    
                currNotBuy= max(prices[idx]+nextBuy,
                            0+nextNotBuy);
    
                nextBuy=currBuy;
                nextNotBuy=currNotBuy;
            }
            return nextBuy;
        }
    };