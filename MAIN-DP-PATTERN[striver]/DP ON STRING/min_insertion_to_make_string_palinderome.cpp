1312. Minimum Insertion Steps to Make a String Palindrome

this is a floow up question of LPS and LCS ....

here the intution goes like ..

keep the longest palindrome substring intact and 
we have to insert the ather memeber reversing it 
so => # of insertion =n-lps(s)

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
        int LPS(string s) {
            string reversed_s=s;
            reverse(reversed_s.begin(), reversed_s.end());
            return LCS(s,reversed_s);
        }
        int minInsertions(string s) {
            int n=s.length();
            return n-LPS(s);
        }
    };

memoization and space optimisation will also works here ..