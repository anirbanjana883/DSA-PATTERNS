44. Wildcard Matching

approach 1: recursn

without shifting of index

time complexity : O(2^(n + m)) // exponential time complexity
space complexity : O(n + m) (stack)

class Solution {
public:
    bool solve(string &s, string &p,int i,int j){
        // base case 
        // Both strings are exhausted: match
        if (i < 0 && j < 0) return true;

        // Pattern exhausted but string remains: no match
        if (i >= 0 && j < 0) return false;

        // String exhausted but pattern remains:
        // only match if remaining pattern is all '*'
        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (p[k-1] != '*') return false;
            }
            return true;
        }

        // explore all ather posobility 
        // becoz * can only matched with one 
        if(p[j]==s[i] || p[j]=='?'){
            return solve(s,p,i-1,j-1);
        }else if(p[j]=='*'){
            return solve(s,p,i-1,j)||solve(s,p,i,j-1);
        }else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return solve(s,p,n-1,m-1);
    }
};

with shifting of index

class Solution {
public:
    bool solve(string &s, string &p,int i,int j){
        // base case 
        // Both strings are exhausted: match
        if (i == 0 && j == 0) return true;

        // Pattern exhausted but string remains: no match
        if (i > 0 && j == 0) return false;

        // String exhausted but pattern remains:
        // only match if remaining pattern is all '*'
        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (p[k-1] != '*') return false;
            }
            return true;
        }

        // explore all ather posobility 
        // becoz * can only matched with one 
        if(p[j-1]==s[i-1] || p[j-1]=='?'){
            return solve(s,p,i-1,j-1);
        }else if(p[j-1]=='*'){
            return solve(s,p,i-1,j)||solve(s,p,i,j-1);
        }else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return solve(s,p,n,m);
    }
};
approach 2: momoization


time complexity : O(m*n) 
space complexity : O(m*n)+O(m+n)

class Solution {
public:
    bool solve(string &s, string &p,int i,int j,vector<vector<int>>&dp){
        // base case 
        // Both strings are exhausted: match
        if (i == 0 && j == 0) return true;

        // Pattern exhausted but string remains: no match
        if (i > 0 && j == 0) return false;

        // String exhausted but pattern remains:
        // only match if remaining pattern is all '*'
        if (i == 0 && j > 0) {
            for (int k = 1; k <= j; k++) {
                if (p[k-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        // explore all ather posobility 
        // becoz * can only matched with one 
        if(p[j-1]==s[i-1] || p[j-1]=='?'){
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        }else if(p[j-1]=='*'){
            return dp[i][j]=solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp);
        }else{
            return false;
        }
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s,p,n,m,dp);
    }
};

approach 3: tabulation 

time complexity : O(m*n) 
space complexity : O(m*n)

class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        // if (i == 0 && j == 0) return true;
        dp[0][0]=true;
        // if (i > 0 && j == 0) return false;
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        // if (i == 0 && j > 0) {
        //     for (int k = 1; k <= j; k++) {
        //         if (p[k-1] != '*') return false;
        //     }
        //     return true;
        // }
        for(int j=1;j<=m;j++) {
            bool flag=true;
            for (int k = 1; k <= j; k++) {
                if (p[k-1] != '*') flag=false;
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]==s[i-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }else{
                    dp[i][j]=false;
                }
            }
        }
        return dp[n][m];
    }
};

approach 4: space optimisation 

time complexity : O(m*n) 
space complexity : O(m)

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base case: empty string and empty pattern
        prev[0] = true;

        // Initialize prev for pattern vs empty string
        for (int j = 1; j <= m; j++) {
            bool allStars = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }
            prev[j] = allStars;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = false; // empty pattern can't match non-empty string
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr; // move to next row
        }

        return prev[m];
    }
};
