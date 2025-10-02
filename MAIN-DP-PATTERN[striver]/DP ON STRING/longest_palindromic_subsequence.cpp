516. Longest Palindromic Subsequence

follow up question for LCS this problem is also known ans LPS 


class Solution {
    public:
        int LCS(string text1, string text2) {
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
        int longestPalindromeSubseq(string s) {
            string reversed_s=s;
            reverse(reversed_s.begin(), reversed_s.end());
            return LCS(s,reversed_s);
        }
    };

memoization and space optimisation will also works here ... 