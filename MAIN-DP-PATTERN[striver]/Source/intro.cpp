509. Fibonacci Number

recursive approach :

time complaexity : O(n)
space complexity : O(2^n) [stack place ]

class Solution {
    public:
        int fib(int n) {
            if(n<=1) return n;
            return fib(n-1)+fib(n-2);
        }
};

memoization approach:

time complaexity : O(n)
space complexity : O(n) [stack place ] + o(n+1) [sp array ]

class Solution {
    public:
        int fibo(int n, vector<int>&dp){
            if(n<=1) return n;
    
            if (dp[n]!=-1) return dp[n];
            return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
        }
    
        int fib(int n) {
            vector<int>dp(n+1,-1);
            return fibo(n,dp);
        }
};

tabulation approach: just look at the recursn and write loop [tabulation]

time complaexity : O(n)
space complexity : O(n) [just the dp array ]

class Solution {
    public:
        int dp[31];
        int fibo(int n){
            dp[0]=0;
            dp[1]=1;
            for(int i=2;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
        int fib(int n) {
            memset(dp,-1,sizeof(dp));
            return fibo(n);
        }
    };

optimal approach : in constant space 

time complaexity : O(n)
space complexity : O(1) 

class Solution {
    public:
        int fib(int n) {
            if (n == 0) return 0; // Base case for n == 0
    
            int prev2 = 0;
            int prev = 1;
    
            for (int i = 2; i <= n; i++) {
                int curr = prev2 + prev;
                prev2 = prev;
                prev = curr;
            }
            return prev;
        }
};
    