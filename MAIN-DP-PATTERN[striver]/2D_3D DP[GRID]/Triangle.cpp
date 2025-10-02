120. Triangle

$$$$$$$$$$
this question is fixed starting point and veriable ending point 
$$$$$$$$$$
the previous provblems are fixed starting and fixed ending problrm 


*one thing you have to notice over here there is no fix ending point 
option 1: starting recursn from the top of the triangle (1 recursn) [better choice] go for it 
option 2: starting recursion from the bottom of the triangle (n no of recursn )

approach 1: recursn 

time complexity is O(2^(m+n))
space complexity is O(m+n)

class Solution {
    public:
        int n,m;
        int solve(int i,int j,vector<vector<int>>& triangle){
            // base case
            if(i==n-1) return triangle[n-1][j];
    
            int down=triangle[i][j]+solve(i+1,j,triangle);
            int diagonal=triangle[i][j]+solve(i+1,j+1,triangle);
    
            return min(down,diagonal);
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            n=triangle.size();
            m=triangle[0].size();
            return solve(0,0,triangle);
        }
    };

approach 2: memoization 

time complexity is O((m*n))
space complexity is O(m*n)+O(m+n) dp array+stack place 

class Solution {
    public:
        int n;
        int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
            // Base case: when we reach the last row
            if (i == n - 1)
                return triangle[i][j];
            // Return the cached result if already computed
            if (dp[i][j] != -1)
                return dp[i][j];
    
            int down = triangle[i][j] + solve(i + 1, j, triangle, dp);
            int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);
    
            // Store the result in dp and return it
            return dp[i][j] = min(down, diagonal);
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            n = triangle.size();
            // Initialize dp with dimensions equal to the triangle's structure
            vector<vector<int>> dp(n, vector<int>(n, -1));
            return solve(0, 0, triangle, dp);
        }
    };
    

here recursn o to n-1 
so tabulation is n-1 to 0; just opposite of recursion.


approach 3: tabulation

time complexity is O((m*n))
space complexity is O(n*n) dp array

keeping in mind the recursion base case 
there may be n number of base case where n is the number 
of rows in triangle. so we will start from n-1 and go to 0.

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<vector<int>>dp(n,vector<int>(n,0));
            // base case
            for(int i=0;i<n;i++){
                dp[n-1][i]=triangle[n-1][i];
            }
    
           /* or ith row there will be 
            i no of column */
            for(int i=n-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int down=triangle[i][j]+dp[i+1][j];
                    int diagonal=triangle[i][j]+dp[i+1][j+1];
    
                    dp[i][j]=min(down,diagonal);
                }
            }
            return dp[0][0];
        }
};
    

approach 3: space optimisation 

time complexity is O((n))
space complexity is O(n) just the prev and curr vector

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            vector<int>prev(n,0);
            // base case
            for(int i=0;i<n;i++){
                prev[i]=triangle[n-1][i];
            }
    
           /* or ith row there will be 
            i no of column */
            for(int i=n-2;i>=0;i--){
                vector<int>curr(n,0);
                for(int j=i;j>=0;j--){
                    int down=triangle[i][j]+prev[j];
                    int diagonal=triangle[i][j]+prev[j+1];
    
                    curr[j]=min(down,diagonal);
                }
                prev=curr;
            }
            return prev[0];
        }
    };
    