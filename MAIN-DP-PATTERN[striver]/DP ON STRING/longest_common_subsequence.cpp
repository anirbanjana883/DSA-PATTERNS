1143. Longest Common Subsequence

approach 1: recursn 

time complexity o((2^n2)*(2^n2))
space complexity O(n+m)

class Solution {
    public:
        int findLcs(string s1, string s2, int idx1, int idx2) {
            // Base case
            if(idx1 == 0 || idx2 == 0) return 0;
    
            // If chars match
            if(s1[idx1-1] == s2[idx2-1]) {
                return  1 + findLcs(s1, s2, idx1-1, idx2-1);
            }
            // If chars don't match
            return  max(findLcs(s1, s2, idx1-1, idx2), 
                                        findLcs(s1, s2, idx1, idx2-1));
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size();
            int n2 = text2.size();
            return findLcs(text1, text2, n1, n2);
        }
    };
    

approach 1: memoization 

time complexity o(n*m)
space complexity o(n*m)++O(n+m)

without shifting of index =>
class Solution {
    public:
        int findLcs(string s1, string s2, int idx1, int idx2, vector<vector<int>>& dp) {
            // Base case
            if(idx1 < 0 || idx2 < 0) return 0;
            if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    
            // If chars match
            if(s1[idx1] == s2[idx2]) {
                return dp[idx1][idx2] = 1 + findLcs(s1, s2, idx1-1, idx2-1, dp);
            }
            // If chars don't match
            return dp[idx1][idx2] = max(findLcs(s1, s2, idx1-1, idx2, dp), 
                                        findLcs(s1, s2, idx1, idx2-1, dp));
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size();
            int n2 = text2.size();
            vector<vector<int>> dp(n1 , vector<int>(n2 , -1));
            return findLcs(text1, text2, n1-1, n2-1, dp);
        }
    };
    

shifting of index =>
class Solution {
    public:
        int findLcs(string s1, string s2, int idx1, int idx2, vector<vector<int>>& dp) {
            // Base case
            if(idx1 == 0 || idx2 == 0) return 0;
            if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    
            // If chars match
            if(s1[idx1-1] == s2[idx2-1]) {
                return dp[idx1][idx2] = 1 + findLcs(s1, s2, idx1-1, idx2-1, dp);
            }
            // If chars don't match
            return dp[idx1][idx2] = max(findLcs(s1, s2, idx1-1, idx2, dp), 
                                        findLcs(s1, s2, idx1, idx2-1, dp));
        }
    
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size();
            int n2 = text2.size();
            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
            return findLcs(text1, text2, n1, n2, dp);
        }
    };
    




    approach 1: tabulaton 
    notice one thing here we need index shifting to handle the base case for ease of tabulation 

    time complexity o(n*m)
    space complexity o(n*m)




    class Solution {
        public:
            int longestCommonSubsequence(string text1, string text2) {
                int n1 = text1.size();
                int n2 = text2.size();
                vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
                for(int i=0;i<n1;i++) dp[i][0]=0;
                for(int j=0;j<n2;j++) dp[0][j]=0;
        
                // as shifting off index happendd
                for(int idx1=1;idx1<=n1;idx1++){
                    for(int idx2=1;idx2<=n2;idx2++){
                        if(text1[idx1-1] == text2[idx2-1]) {
                            dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                        }
                        // If chars don't match
                         else dp[idx1][idx2] = max(dp[idx1-1][idx2], 
                                                    dp[idx1][idx2-1]);
                    }
                }
                return dp[n1][n2];
            }
        };


approach 1: space optimisation  
notice one thing here we need index shifting to handle the base case for ease of tabulation 
    
time complexity o(n*m)
space complexity o(n)

class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size();
            int n2 = text2.size();
            vector<int>prev(n2+1,0);
            vector<int>curr(n2+1,0);
    
            // as shifting off index happendd
            for(int idx1=1;idx1<=n1;idx1++){
                for(int idx2=1;idx2<=n2;idx2++){
                    if(text1[idx1-1] == text2[idx2-1]) {
                        curr[idx2] = 1 + prev[idx2-1];
                    }
                    // If chars don't match
                     else curr[idx2] = max(prev[idx2],curr[idx2-1]);
                }
                prev=curr;
            }
            return prev[n2];
        }
    };
    