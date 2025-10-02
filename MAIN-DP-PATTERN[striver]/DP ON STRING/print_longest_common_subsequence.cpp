print longest Common Subsequence [question in no platform]
this is a follow up question of LCS <:'.':>

approach : derived from LCS

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
            // return dp[n1][n2];
            //  printing the common subsequence o(n1+n2)

            int len=dp[n1][n2];
            string ans="";
            for(int i=0;i<len=;i++){
                ans+='#';
            }
            int i=n1,j=n2;
            int index=len-1;
            while(i>0 && j>0){
                if(text1[i-1]==text2[j-1]){
                    ans[index]=s[i-1];
                    index--;
                    i--,j--;
                }else if (dp[i-1][j]>dp[i][j-1]){
                    i--;
                }else{
                    j--;
                }
            }
            return ans;
        }
    };