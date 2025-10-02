Longest Common Substring [gfg]

REMEMBER : substring must have to be continious ...

the slight modification from the code of lcs is 
whenevr we get same thats ok but if dont get any match then take 0;



class Solution {
    public:
      int longestCommonSubstr(string& text1, string& text2) {
          // your code here
          int n1 = text1.size();
          int n2 = text2.size();
          vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
          for(int i=0;i<n1;i++) dp[i][0]=0;
          for(int j=0;j<n2;j++) dp[0][j]=0;
      
          // as shifting off index happendd
          // we have to return the overall maximum dp table
          int ans=0;
          for(int idx1=1;idx1<=n1;idx1++){
              for(int idx2=1;idx2<=n2;idx2++){
                  if(text1[idx1-1] == text2[idx2-1]) {
                      dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
                      ans=max(ans,dp[idx1][idx2]);
                  }
                  // If chars don't match
                  // here is the slight modification of LCS code 
                   else dp[idx1][idx2] = 0;
              }
          }
        }
    };
similarly space optimizzation canbe applied like previous LCS ..

s1 = "ABCDGH", s2 = "ACDGHR"
0000000
0100000
0000000
0010000
0002000
0000300
0000040
