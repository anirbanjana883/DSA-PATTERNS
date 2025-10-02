2327. Number of People Aware of a Secret

resursion + memoization 

class Solution {
public:

    // time complexity : O(n * (forget - delay))
    // space complexity : O(n) + O(n)  // dp array + recursion stack space
    
    
    int M = 1e9 + 7;
    vector<int>dp;
    int solve(int day, int delay, int forget){
        if( day == 1) return 1;

        if(dp[day] != -1) return dp[day];
        int result = 0;
        for(int prev = day - forget + 1;prev <= day - delay; prev ++){
            if(prev > 0) result = (result + solve(prev,delay,forget)) % M;
        }
        return dp[day] = result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total = 0;
        dp.assign(n + 1 , -1);
        for(int day = n - forget + 1;day <= n; day ++){
            if(day > 0) total = (total + solve(day,delay,forget)) % M;
        }
        return total;
    }
};

bottom up dp :

dp[day] = number of people who learn the secret on that day


class Solution {
public:
    int M = 1e9 + 7;
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n + 1);
        dp[1] = 1;
        for(int day = 2;day <= n; day ++){
            int result = 0;
            for(int prev = day - forget + 1;prev <= day - delay; prev ++){
                if(prev > 0) result = (result + dp[prev]) % M;
            }
            dp[day] = result;
        }
        int count = 0;
        for(int day = n - forget + 1;day <= n; day ++){
            if(day > 0) count = (count + dp[day]) % M;
        } 
        return count;
    }
};