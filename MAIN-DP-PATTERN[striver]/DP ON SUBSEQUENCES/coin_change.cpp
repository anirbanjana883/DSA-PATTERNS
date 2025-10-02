322. Coin Change

key point : Return the fewest number of coins that you need to make up that amount.  

f(idx,t) minimum number of coins to form target amount using coins from given indices

## remember one thing that whenever there is a 
        1. infinite supply 
        2. multiple use 
        >>> no change in index will happend  /  (no ind+1) or (no ind-1) 

approach 1:recursn 

time complexity:O(2^n) 
space complexity:O(amount) auxiliary space (because same coin can be used many time ) so at worst this can be s.c

class Solution {
    public: 
        int solve(vector<int>& coins,int idx,int amount){
            // base case
            if (amount==0) return 0;
            if(idx==0){
                if(amount % coins[0]==0){
                    // we can get coin
                    return amount/coins[0];
                }
                // else if we take infinite coin we can not 
                // coin because one number is therte and it is not divisible 
                else return 1e9;
            }
            // explore 
            int not_take=0+solve(coins,idx-1,amount);
            int take=INT_MAX;
            if(coins[idx]<=amount){
                // that if we divide amount by coin[idx] we get 1 coin
                // as we can take infite no of coin so no change in idx 
                take=1+solve(coins,idx,amount-coins[idx]); 
            }
            return min(take,not_take);
        }
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            int res= solve(coins,n-1,amount);
            return res==1e9?-1:res;
        }
    };

approach 1:memoization 

time complexity:O(n*amount) 
space complexity:O(amount)+O(n*amount) auxiliary recursn stack place .. 

class Solution {
    public: 
        int solve(vector<int>& coins,int idx,int amount,vector<vector<int>>&dp){
            // base case
            if (amount==0) return 0;
            if(idx==0){
                if(amount % coins[0]==0){
                    // we can get coin
                    return amount/coins[0];
                }
                // else if we take infinite coin we can not 
                // coin because one number is therte and it is not divisible 
                else return 1e9;
            }
            if(dp[idx][amount]!=-1) return dp[idx][amount];
            // explore 
            int not_take=0+solve(coins,idx-1,amount,dp);
            int take=INT_MAX;
            if(coins[idx]<=amount){
                // that if we divide amount by coin[idx] we get 1 coin
                // as we can take infite no of coin so no change in idx 
                take=1+solve(coins,idx,amount-coins[idx],dp); 
            }
            return dp[idx][amount]=min(take,not_take);
        }
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,-1));
            int res= solve(coins,n-1,amount,dp);
            return res==1e9?-1:res;
        }
    };

approach 3: Tabulation 

time complexity:O(n*W) 
space complexity:O(n*W)

class Solution {
public: 
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        // base case
        for(int amount=0;amount<=target;amount++){
            if(amount%coins[0]==0){
                dp[0][amount]=amount/coins[0];
            }else{
                dp[0][amount]=1e9;
            }
        }
        // explore
        for(int idx=1;idx<n;idx++){
            for(int amount=0;amount<=target;amount++){
                int not_take=0+dp[idx-1][amount];
                int take=1e9;
                if(coins[idx]<=amount){
                    // that if we divide amount by coin[idx] we get 1 coin
                    // as we can take infite no of coin so no change in idx 
                    take=1+dp[idx][amount-coins[idx]]; 
                }
                dp[idx][amount]=min(take,not_take);
            }
        }
        int ans= dp[n-1][target];
        if(ans==1e9) return -1;
        return ans;
    }
};

approach 1:space optimisation 

time complexity:O(n*W) 
space complexity:O(W) auxiliary recursn stack place .. 

class Solution {
public: 
    int coinChange(vector<int>& coins, int target) {
        int n=coins.size();
       vector<int>prev(target+1),curr(target+1);
        // base case
        for(int amount=0;amount<=target;amount++){
            if(amount%coins[0]==0){
                prev[amount]=amount/coins[0];
            }else{
                prev[amount]=1e9;
            }
        }
        // explore
        for(int idx=1;idx<n;idx++){
            for(int amount=0;amount<=target;amount++){
                int not_take=0+prev[amount];
                int take=1e9;
                if(coins[idx]<=amount){
                    // that if we divide amount by coin[idx] we get 1 coin
                    // as we can take infite no of coin so no change in idx 
                    take=1+curr[amount-coins[idx]]; 
                }
                curr[amount]=min(take,not_take);
            }
            prev=curr;
        }
        int ans= prev[target];
        if(ans==1e9) return -1;
        return ans;
    }
};