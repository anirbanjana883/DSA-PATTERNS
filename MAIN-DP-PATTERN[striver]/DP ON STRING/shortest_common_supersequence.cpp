1092. Shortest Common Supersequence 

prerequistics LCS and PRINT LCS problem

first fill dp table with help of lcs code the apply the remaining code

time complexity O(n*m) 
space complexity O(n*m)

class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
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

        string ans="";
        int i=n1,j=n2;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans+=text1[i-1];
                i--,j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans+=text1[i-1];
                i--;
            }else{
                ans+=text2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=text1[i-1];
            i--;
        }
        while(j>0){
            ans+=text2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};