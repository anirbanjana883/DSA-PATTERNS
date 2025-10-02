1463. Cherry Pickup II
>>3D dp question<<<
appproach 1: recursn

class Solution {
    public:
        // time complexity o((3^n)*(3^n))
        // space complexity o(n) the path of robot visited
        int m,n;
        vector<int>direction={-1,0,1};
        int giveAns(vector<vector<int>>& grid,int i,int c1,int c2){
            // base case 
            if(c1<0 || c1>=n || c2<0 || c2>=n) return -1e8;
            // robots reach to destinaion
            if(i==m-1){
                if(c1==c2){ // path will be counted once
                    return grid[i][c1];
                }else{ // both path should be counted
                    return grid[i][c1]+grid[i][c2];
                }
            }
            // if robots are in the cell ather then last row
            int maxCherry=0;
            for(auto &x:direction){
                for(auto &y:direction){
                    int cherry=0;
                    if(c1==c2){ //both in same celll
                        cherry=grid[i][c1];
                    }else{
                        cherry=grid[i][c1]+grid[i][c2];
                    }
                    // explore ather pat
                    cherry+=giveAns(grid,i+1,c1+x,c2+y);
                    maxCherry=max(maxCherry,cherry);
                }
            }
            return maxCherry;
        }
        int cherryPickup(vector<vector<int>>& grid) {
            m=grid.size();
            n=grid[0].size();
    
            return giveAns(grid,0,0,n-1);
        }
    };

approach 2: memoization

class Solution {
    public:
        // time complexity o(m*n*n)
        // space complexity o(m*n*n)+o(n) the path of robot visited
        int m,n;
        vector<int>direction={-1,0,1};
        int giveAns(vector<vector<int>>& grid,int i,int c1,int c2,vector<vector<vector<int>>>&dp){
            // base case 
            if(c1<0 || c1>=n || c2<0 || c2>=n) return -1e8;
            // robots reach to destinaion
            if(i==m-1){
                if(c1==c2){ // path will be counted once
                    return grid[i][c1];
                }else{ // both path should be counted
                    return grid[i][c1]+grid[i][c2];
                }
            }
            if(dp[i][c1][c2]!=-1) return dp[i][c1][c2];
            // if robots are in the cell ather then last row
            int maxCherry=0;
            for(auto &x:direction){
                for(auto &y:direction){
                    int cherry=0;
                    if(c1==c2){ //both in same celll
                        cherry=grid[i][c1];
                    }else{
                        cherry=grid[i][c1]+grid[i][c2];
                    }
                    // explore ather pat
                    cherry+=giveAns(grid,i+1,c1+x,c2+y,dp);
                    maxCherry=max(maxCherry,cherry);
                }
            }
            return dp[i][c1][c2]=maxCherry;
        }
        int cherryPickup(vector<vector<int>>& grid) {
            m=grid.size();
            n=grid[0].size();
            vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
            return giveAns(grid,0,0,n-1,dp);
        }
    };
appproach 3: tabulation

class Solution {
    public:
        // time complexity o(m*n*n)
        // space complexity o(m*n*n) no recursn stack place
    int m,n;
    vector<int>direction={-1,0,1};
    
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        // bas e case
        // i==m-1
        for(int c1=0;c1<n;c1++){
            for(int c2=0;c2<n;c2++){
                if(c1==c2) dp[m-1][c1][c2]=grid[m-1][c1]; // both robot in smae cell
                else dp[m-1][c1][c2]=grid[m-1][c1]+grid[m-1][c2]; // in differemt cell
            }
        }
        for(int i=m-2;i>=0;i--){
            for(int c1=0;c1<n;c1++){
                for(int c2=0;c2<n;c2++){
                        
                     // if robots are in the cell ather then last row
                    int maxCherry=0;
                    for(auto &x:direction){
                         for(auto &y:direction){
                            int cherry=0;
                            if(c1==c2){ //both in same celll
                                cherry=grid[i][c1];
                            }else{ // both in different cell
                                cherry=grid[i][c1]+grid[i][c2];
                            }
                            // explore ather pat
                            if(c1+x >= 0 && c1+x < n && c2+y >= 0 && c2+y < n){
                                cherry+=dp[i+1][c1+x][c2+y];
                            }else {
                                cherry+=-1e8;
                            }
                            maxCherry=max(maxCherry,cherry);
                        }
                    }
                     dp[i][c1][c2]=maxCherry;
                }
            }
        }
            return dp[0][0][n-1];
        }   
    };
    
appproach 4: space optimization 