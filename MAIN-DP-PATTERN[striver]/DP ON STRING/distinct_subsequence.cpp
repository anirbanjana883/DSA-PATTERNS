115. Distinct Subsequences

approach 1: recursn 

time complexity : o(2^n)
space complexity : o(n)

class Solution {
public:
    int solve(string &s,string &t,int i,int j){
        // base case
        if(j==0) return 1;
        if(i==0) return 0;

        if(s[i-1]==t[j-1]){
            //          take                not take
            return solve(s,t,i-1,j-1) + solve(s,t,i-1,j);
        }else{ // not matched so not take 
            return solve(s,t,i-1,j);
        }
     }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        return solve(s,t,n,m);
    }
};

approach 1: memoization 

time complexity : o(n*m)
space complexity : o(n*m)+o(n)

class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        // base case
        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
            //          take                not take
            return dp[i][j]=solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
        }else{ // not matched so not take 
            return dp[i][j]=solve(s,t,i-1,j,dp);
        }
     }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,n,m,dp);
    }
};

approach 2: memoization 

time complexity : o(n*m)
space complexity : o(n*m)+o(n)

class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        // base case
        if(j==0) return 1;
        if(i==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
            //          take                not take
            return dp[i][j]=solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
        }else{ // not matched so not take 
            return dp[i][j]=solve(s,t,i-1,j,dp);
        }
     }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,t,n,m,dp);
    }
};

approach 3: tabuletion 

time complexity : o(n*m)
space complexity : o(n*m)

class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        // empty t can be matched in any prefix of s
        for(int i=0; i<=n; i++) dp[i][0] = 1;  
        // non-empty t cannot be matched with empty s
        for(int j=1; j<=m; j++) dp[0][j] = 0;  

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    //          take                not take
                    dp[i][j]=dp[i-1][j-1] + dp[i-1][j];
                }else{ // not matched so not take 
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};

approach 3: space optimisation 

time complexity : o(n*m)
space complexity : o(n)

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> curr(m + 1, 0), prev(m + 1, 0);

        prev[0] = 1;  // base case: empty t

        for (int i = 1; i <= n; i++) {
            curr[0] = 1;  // empty t can be formed from any prefix of s
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j - 1] + prev[j];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return (int) prev[m];
    }
};
