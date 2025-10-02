403. Frog Jump

recursn :
class Solution {
public:
    // time o(3 ^ n)
    // space o(n) + o ( n )
    bool solve(vector<int>& stones,int idx,int n , int k ,unordered_map<int,int>&mp){
        // bc
        if(idx == n -1){
            return true;
        }
        if(k > 0 && mp.find(stones[idx] + k) != mp.end()){
            if(solve(stones,mp[stones[idx] + k],n,k,mp) == true) return true;;
        }
        if( k + 1 > 0 && mp.find(stones[idx] + k + 1) != mp.end()){
            if(solve(stones,mp[stones[idx] + k + 1],n,k + 1,mp)==true)  return true;
        }
        if(k - 1 > 0 && mp.find(stones[idx] + k - 1) != mp.end()){
            if(solve(stones,mp[stones[idx] + k - 1],n,k - 1,mp) == true) return true;
        } 
        return false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 0) return true;
        if(stones[1] != 1) return false; 
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        
        return solve(stones, 1, n, 1, mp);
    }
};

memoization :

class Solution {
public:
    // time o( n ^ 2)
    // space o ( n ^ 2) o ( n) + o (n)
    bool solve(vector<int>& stones,int idx,int n , int k ,unordered_map<int,int>&mp,vector<vector<int>>&dp){
        // bc
        if(idx == n -1){
            return true;
        }
        if(dp[idx][k] != -1) return dp[idx][k];
        if(k > 0 && mp.find(stones[idx] + k) != mp.end()){
            if(solve(stones,mp[stones[idx] + k],n,k,mp,dp) == true) return true;;
        }
        if( k + 1 > 0 && mp.find(stones[idx] + k + 1) != mp.end()){
            if(solve(stones,mp[stones[idx] + k + 1],n,k + 1,mp,dp)==true)  return true;
        }
        if(k - 1 > 0 && mp.find(stones[idx] + k - 1) != mp.end()){
            if(solve(stones,mp[stones[idx] + k - 1],n,k - 1,mp,dp) == true) return true;
        } 
        return dp[idx][k]=false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 0) return true;
        if(stones[1] != 1) return false; 
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , -1));
        return solve(stones, 1, n, 1, mp , dp);
    }
};

tabulation :


class Solution {
public:
    // time o( n ^ 2)
    // space o ( n ^ 2) o ( n) + o (n)
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(n == 0) return true;
        if(stones[1] != 1) return false; 
        
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<bool>>dp(n + 1 , vector<bool>(n + 1 , false));
        for(int k = 0 ; k <= n ; k++){
            dp[n - 1][k] = true;
        }
        for(int idx = n - 2 ; idx >= 0 ;idx --){
            for(int k = 1 ; k < n; k++){
                bool result = false;
                if(mp.find(stones[idx] + k) != mp.end()){
                    if(dp[mp[stones[idx] + k]][k] == true) result = true;
                }
                if(mp.find(stones[idx] + k + 1) != mp.end()){
                    if(dp[mp[stones[idx] + k + 1]][k + 1] ==true)  result = true;
                }
                if(mp.find(stones[idx] + k - 1) != mp.end()){
                    if(dp[mp[stones[idx] + k - 1]][k - 1] == true) result = true;
                } 
                dp[idx][k]=result;
            }   
        }

        return dp[1][1];
    }
};