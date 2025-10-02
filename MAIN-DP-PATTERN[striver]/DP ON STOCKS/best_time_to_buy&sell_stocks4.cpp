188. Best Time to Buy and Sell Stock IV

same code of [123. Best Time to Buy and Sell Stock III] will works here .....

# You may complete at most *k transactions*
# but  may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time
over here we are bound to do atmost 2 transactions
onr trancation = buy+sell;
approach 1: recursn

time complexity : o(2^n)
space complexity : o(n)

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int transactionNo,int k){
            /* for 2 transaction -> 4
                for k transaction -> 2*k*/
            if(idx==n || transactionNo==2*k) return 0;
            int profit=0;
            if(transactionNo % 2==0){ // buy but not sell
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1,k),
                                        0+findMaxProfit(prices,idx+1,transactionNo,k));
            }else{ // not buy but sell
                profit=max(prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1,k),
                                        0+findMaxProfit(prices,idx+1,transactionNo,k));
            }
            return profit;
        }
        int maxProfit(int k, vector<int>& prices) {
            n=prices.size();
            // vector<vector<int>>dp(n,vector<int>(4,-1));
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            return findMaxProfit(prices,0,0,k);
        }
    };

approach 1: memoization 

time complexity : o(n*2*k)
space complexity : o(n*2*k)+(n) dp table + recursn stack  

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int transactionNo,int k,vector<vector<int>>&dp){
            if(idx==n || transactionNo==2*k) return 0;
            if(dp[idx][transactionNo]!=-1) return dp[idx][transactionNo];
            int profit=0;
            if(transactionNo % 2==0){ // buy but not sell
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1,k,dp),
                                        0+findMaxProfit(prices,idx+1,transactionNo,k,dp));
            }else{ // not buy but sell
                profit=max(prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1,k,dp),
                                        0+findMaxProfit(prices,idx+1,transactionNo,k,dp));
            }
            return dp[idx][transactionNo]=profit;
        }
        int maxProfit(int k, vector<int>& prices) {
            n=prices.size();
            vector<vector<int>>dp(n,vector<int>(2*k,-1));
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            return findMaxProfit(prices,0,0,k,dp);
        }
    };

approach 1: tabulation

time complexity : o(n*2*k)
space complexity : o(n*2*k) no recursn stack space 

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        /*  b s b s
            0 1 2 3 -> tarnscation numbers 
        only on even tranaction number -> buy
        only on odd tranaction number -> sell */
        for(int transactionNo=0;transactionNo<2*k;transactionNo++){
            dp[n][transactionNo]=0;
        }
        for(int idx=0;idx<n;idx++){
            dp[idx][2*k]=0;
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int transactionNo=0;transactionNo<2*k;transactionNo++){
                int profit=0;
                if(transactionNo % 2==0){ // buy but not sell
                    profit=max(-prices[idx]+dp[idx+1][transactionNo+1],
                                        dp[idx+1][transactionNo]);
                }else{ // not buy but sell
                    profit=max(prices[idx]+dp[idx+1][transactionNo+1],
                                        dp[idx+1][transactionNo]);
                }
                dp[idx][transactionNo]=profit;
            }
        }
        return dp[0][0];
        }
    };

approach 1: space optimization

time complexity : o(n*2*k)
space complexity : o(2*k)

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n=prices.size();
            vector<int>next(2*k+1,0);
            vector<int>curr(2*k+1,0);
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            for(int idx=n-1;idx>=0;idx--){
                for(int transactionNo=0;transactionNo<2*k;transactionNo++){
                    int profit=0;
                    if(transactionNo % 2==0){ // buy but not sell
                        profit=max(-prices[idx]+next[transactionNo+1],
                                            next[transactionNo]);
                    }else{ // not buy but sell
                        profit=max(prices[idx]+next[transactionNo+1],
                                            next[transactionNo]);
                    }
                    curr[transactionNo]=profit;
                }
                next=curr;
            }
            return next[0];
        }
    };
