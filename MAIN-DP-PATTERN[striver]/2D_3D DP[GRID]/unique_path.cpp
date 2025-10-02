62. Unique Paths

constarein => The robot can only move either down or right at any point in time.

approach 1:recursn 

express evrthing in terms of (i,j)
do all possible stuff on that index
store (max/min) ans according to the question 

we are starting of with the destination and go to the source in recursn (top down)

time complexity:O(2^(n*m)) for each element we have 2 choices (right or down) but we starting from last so (left or up)
space complexity:O(n+m) path length 

class Solution {
    public:
        int solve(int i,int j){
            // base case
            if(i==0 && j==0 ){
                // we havw reached our destination
                // so we should count this path 
                return 1;
            }
            if(i<0 || j<0) return 0;// index out of bound 
    
            int up =solve(i-1,j);
            int left=solve(i,j-1);
    
            return up+left;
        }
        int uniquePaths(int m, int n) {
            return solve(m-1,n-1);
        }
    };

    approach 2:memoization  

    time complexity:O(n*m) because at max each cell can be called for once 
    space complexity:O((n-1)+(m-1))+o(n*m) path length+recusn stack space 

    class Solution {
        public:
            int solve(int i,int j,vector<vector<int>>&dp){
                // base case
                if(i==0 && j==0 ){
                    // we havw reached our destination
                    // so we should count this path 
                    return 1;
                }
                if(i<0 || j<0) return 0;// index out of bound 
                if(dp[i][j]!=-1){
                    return dp[i][j];
                }
        
                return dp[i][j]=solve(i-1,j,dp)+solve(i,j-1,dp);
            }
            int uniquePaths(int m, int n) {
                vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
                return solve(m-1,n-1,dp);
            }
        };


approach 3:tabulation  

time complexity:O(n*m) because at max each cell can be called for once 
space complexity:O(n-1)+(m-1)) no recursn stack space  

class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>>dp(m,vector<int>(n,0));
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 && j==0) dp[i][j]=1; // bas case
    
                    else{
                        int up=0,left=0; // if i<0 or j<0 up and left will be zero
                        if(i>0) up=dp[i-1][j];
                        if(j>0) left=dp[i][j-1];
    
                        dp[i][j]=up+left;
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };


    approach 4:space optimization  

    time complexity:O(n*m) because at max each cell can be called for once 
    space complexity:O(1)

    class Solution {
        public:
            int uniquePaths(int m, int n) {
                vector<int>prev(n,0);
                for(int i=0;i<m;i++){
                    vector<int>curr(n,0);
                    for(int j=0;j<n;j++){
                        if(i==0 && j==0) curr[j]=1; // bas case
        
                        else{
                            int up=0,left=0; // if i<0 or j<0 up and left will be zero
                            if(i>0) up=prev[j]; // here row is the previous row 
                            if(j>0) left=curr[j-1]; // here row is the curr row
        
                            curr[j]=up+left;
                        }
                    }
                    prev=curr;
                }
                return prev[n-1];
            }
        };

follow up question >  63. Unique Paths II [exact same question ]