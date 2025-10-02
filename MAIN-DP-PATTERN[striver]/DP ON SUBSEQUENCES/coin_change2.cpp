518. Coin Change II

key point : Return the number of combinations that make up that amount. 

f(idx,t) minimum number of coins to form target amount using coins from given indices

## remember one thing that whenever there is a 
        1. infinite supply 
        2. multiple use 
        >>> no change in index will happend  /  (no ind+1) or (no ind-1) 

approach 1:recursn 

time complexity:exponential
space complexity:>>O(amount) auxiliary space (because same coin can be used many time ) so at worst this can be s.c

class Solution {
public:
    int solve(vector<int>& coins,int idx,int T){
        // base case
        if(idx==0){
            return T%coins[0]==0;
        }
        // explore all posibilities
        int not_take=solve(coins,idx-1,T);
        int take=0;
        if(coins[idx]<=T){
            take=solve(coins,idx,T-coins[idx]);
        }
        return take+not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(coins,n-1,amount);
    }
};

approach 1:memoization 

time complexity:O(n*amount) 
space complexity:O(amount)+O(n*amount) auxiliary recursn stack place .. 

class Solution {
public:
    int solve(vector<int>& coins, int idx, int T, vector<vector<int>>& dp) {
        // base case
        if (idx == 0) {
            return T % coins[0] == 0;
        }
        if (dp[idx][T] != -1) return dp[idx][T];
        
        // explore all possibilities
        int not_take = solve(coins, idx - 1, T, dp);
        int take = 0;
        if (coins[idx] <= T) {
            take = solve(coins, idx, T - coins[idx], dp);
        }
        return dp[idx][T] = take + not_take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1)); 
        return solve(coins, n - 1, amount, dp);
    }
};


approach 3: Tabulation 

time complexity:O(n*W) 
space complexity:O(n*W)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return 0;

        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) dp[0][T] = 1;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int T = 0; T <= amount; T++) {
                long long not_take = dp[idx - 1][T];
                long long take = 0;
                if (coins[idx] <= T) {
                    take = dp[idx][T - coins[idx]];
                }
                dp[idx][T] = take + not_take; /
            }
        }

        return dp[n - 1][amount];
    }
};


approach 1:space optimisation 

time complexity:O(n*W) 
space complexity:O(W) auxiliary recursn stack place .. 

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.empty()) return 0;

        int n = coins.size();
        vector<int>prev(amount+1,0),curr(amount+1,0);

        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) prev[T] = 1;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int T = 0; T <= amount; T++) {
                long long not_take = prev[T];
                long long take = 0;
                if (coins[idx] <= T) {
                    take = curr[T - coins[idx]];
                }
                curr[T] = take + not_take; 
            }
            prev=curr;
        }

        return prev[amount];
    }
};
