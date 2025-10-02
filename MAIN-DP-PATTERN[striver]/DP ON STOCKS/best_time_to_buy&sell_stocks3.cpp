123. Best Time to Buy and Sell Stock III

$$ question of 3D dp

# You may complete at most *two transactions*
# but  may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time
over here we are bound to do atmost 2 transactions
onr trancation = buy+sell;
approach 1: recursn

time complexity : o(2^n)
space complexity : o(n)

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int buy,int cap){
            // base case
            if(idx==n) return 0;
            if(cap==0) return 0;
            int profit=0;
            if(buy){ // can buy buy can not sell
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,0,cap),
                                        findMaxProfit(prices,idx+1,1,cap));
                // although buy but can not sold so no change in cap
            }else{ // can not buy but can sell
                profit=max(prices[idx]+findMaxProfit(prices,idx+1,1,cap-1),
                                        findMaxProfit(prices,idx+1,0,cap));
                // when buy isf sell (in first case) then cap decrease
                // atherwise cap remain unchanged...
            }
            return profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            //   prices , idx , buy , cap
            // cap =number of trancation allowed
            return findMaxProfit(prices,0,1,2);
        }
    };

approach 2: memoization 

time complexity : o(n*2*3)
space complexity : o(n*2*3)+(n) dp table + recursn stack  

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int buy,int cap,vector<vector<vector<int>>>&dp){
            if(idx==n) return 0;
            if(cap==0) return 0;
            if(dp[idx][buy][cap]!=-1){
                 return dp[idx][buy][cap];
            }
            int profit=0;
            if(buy){ 
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,0,cap,dp),
                                        findMaxProfit(prices,idx+1,1,cap,dp));           
            }else{ 
                profit=max(prices[idx]+findMaxProfit(prices,idx+1,1,cap-1,dp),
                                        findMaxProfit(prices,idx+1,0,cap,dp));
            }
            return dp[idx][buy][cap]=profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            // o,1,2 transaction remaining
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
            return findMaxProfit(prices,0,1,2,dp);
        }
    };

approach 3: tabulation

time complexity : o(n*2*3)
space complexity : o(n*2*3) no recursn stack space 

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            // o,1,2 transaction remaining
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
            // if(idx==n) return 0;
            // no need of writting the base case since all item are zero 
            for(int buy=0;buy<=1;buy++){
                for(int cap=0;cap<=2;cap++){
                    dp[n][buy][cap]=0;
                }
            }
            // if(cap==0) return 0;
            // no need of writting the base case since all item are zero 
            for(int idx=0;idx<n;idx++){
                for(int buy=0;buy<=1;buy++){
                    dp[idx][buy][0]=0;
                }
            }
            for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
                        int profit=0;
                        if(buy){ 
                            profit=max(-prices[idx]+dp[idx+1][0][cap],
                                           dp[idx+1][1][cap]);           
                        }else{ 
                            profit=max(prices[idx]+dp[idx+1][1][cap-1],
                                            dp[idx+1][0][cap]);
                        }
                        dp[idx][buy][cap]=profit;
                    }
                }
            }
            return dp[0][1][2];
        }
    };

approach 4: space optimization

time complexity : o(n)
space complexity : o(2*3)=o(1)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            // o,1,2 transaction remaining
            vector<vector<int>>curr(2,vector<int>(3,0));
            vector<vector<int>>next(2,vector<int>(3,0));
    
            for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
                        int profit=0;
                        if(buy){ 
                            profit=max(-prices[idx]+next[0][cap],
                                           next[1][cap]);           
                        }else{ 
                            profit=max(prices[idx]+next[1][cap-1],
                                            next[0][cap]);
                        }
                        curr[buy][cap]=profit;
                    }
                }
                next=curr;
            }
            return next[1][2];
        }
    };

making the question a 2d DP question..

approach 1: another approach : of solving this question 
using tarnscation number

for this watch striver explanation ->
time complexity : o(2^n)
space complexity : o(n)

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int transactionNo){
            if(idx==n || transactionNo==4) return 0;
            int profit=0;
            if(transactionNo % 2==0){ // buy but not sell
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1),
                                      findMaxProfit(prices,idx+1,transactionNo));
            }else{ // not buy but sell
                profit=max(prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1),
                                      findMaxProfit(prices,idx+1,transactionNo));
            }
            return profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            // vector<vector<int>>dp(n,vector<int>(4,-1));
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            return findMaxProfit(prices,0,0);
        }
    };


approach 2: memoization 
using tarnscation number

time complexity : o(n*4)
space complexity : o(n*4)+o(n) dp table + recursn stack space

class Solution {
    public:
        int n;
        int findMaxProfit(vector<int>& prices,int idx,int transactionNo,vector<vector<int>>&dp){
            if(idx==n || transactionNo==4) return 0;
            int profit=0;
            if(dp[idx][transactionNo]!=-1) return dp[idx][transactionNo];
            if(transactionNo % 2==0){ // buy but not sell
                profit=max(-prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1,dp),
                                      findMaxProfit(prices,idx+1,transactionNo,dp));
            }else{ // not buy but sell
                profit=max(prices[idx]+findMaxProfit(prices,idx+1,transactionNo+1,dp),
                                      findMaxProfit(prices,idx+1,transactionNo,dp));
            }
            return dp[idx][transactionNo]=profit;
        }
        int maxProfit(vector<int>& prices) {
            n=prices.size();
            vector<vector<int>>dp(n,vector<int>(4,-1));
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            return findMaxProfit(prices,0,0,dp);
        }
    };


approach 3: tabulation
using tarnscation number
    
time complexity : o(n*4)
space complexity : o(n*4)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>dp(n+1,vector<int>(5,0));
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            for(int transactionNo=0;transactionNo<4;transactionNo++){
                dp[n][transactionNo]=0;
            }
            for(int idx=0;idx<n;idx++){
                dp[idx][4]=0;
            }
            for(int idx=n-1;idx>=0;idx--){
                for(int transactionNo=0;transactionNo<4;transactionNo++){
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

approach 3: space optimisation
using tarnscation number
        
time complexity : o(n*4)
space complexity : o(1)

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<int>next(5,0);
            vector<int>curr(5,0);
            /*  b s b s
                0 1 2 3 -> tarnscation numbers 
            only on even tranaction number -> buy
            only on odd tranaction number -> sell */
            for(int idx=n-1;idx>=0;idx--){
                for(int transactionNo=0;transactionNo<4;transactionNo++){
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