72. Edit Distance

methode 1:without index shifting :

approach 1: recursn 

time complexity : O(3^(m+n)) // exponential time complexity
space complexity : O(m+n)

class Solution {
public:
    int solve(string &s1, string &s2,int i,int j){
        // base case 
        if(i<0) return j+1;
        if(j<0) return i+1;
        // elplore all ather posobilities 
        // matched 
        if(s1[i]==s2[j]){
            return 0+solve(s1,s2,i-1,j-1);
        }else{ // not matched 
            return 1+ min(solve(s1,s2,i,j-1),min(solve(s1,s2,i-1,j),solve(s1,s2,i-1,j-1)));
            //           insertion                  deletion              replace 
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return solve(word1,word2,n-1,m-1);
    }
};

methode 1: with index shifting :

approach 1: recursn

time complexity : O(3^(m+n)) // exponential time complexity
space complexity : O(m+n)

class Solution {
public:
    int solve(string &s1, string &s2,int i,int j){
        // base case 
        if(i==0) return j;
        if(j==0) return i;
        // elplore all ather posobilities 
        // matched 
        if(s1[i-1]==s2[j-1]){
            return 0+solve(s1,s2,i-1,j-1);
        }else{ // not matched 
            return 1+ min(solve(s1,s2,i,j-1),min(solve(s1,s2,i-1,j),solve(s1,s2,i-1,j-1)));
            //           insertion                  deletion              replace 
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return solve(word1,word2,n,m);
    }
};

approach 2: momoization

time complexity : O(m*n) 
space complexity : O(m*n)+O(m+n)

class Solution {
public:
    int solve(string &s1, string &s2,int i,int j,vector<vector<int>>&dp){
        // base case 
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        // elplore all ather posobilities 
        // matched 
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=0+solve(s1,s2,i-1,j-1,dp);
        }else{ // not matched 
            return dp[i][j]=
            1+ min(solve(s1,s2,i,j-1,dp),min(solve(s1,s2,i-1,j,dp),solve(s1,s2,i-1,j-1,dp)));
            //              insertion                  deletion              replace 
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(word1,word2,n,m,dp);
    }
};

approach 3: tabulation 

time complexity : O(m*n) 
space complexity : O(m*n)

class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=0;i<=n;i++) dp[i][0]=i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=0+dp[i-1][j-1];
                }else{ // not matched 
                    dp[i][j]= 1+ min(dp[i][j-1],  // insertion
                                min(dp[i-1][j], // deletion
                                dp[i-1][j-1])); // replace
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
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);

        for(int j=0;j<=m;j++) prev[j]=j;

        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    curr[j]=0+prev[j-1];
                }else{ // not matched 
                    curr[j]= 1+ min(curr[j-1],  // insertion
                                min(prev[j], // deletion
                                prev[j-1])); // replace
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};