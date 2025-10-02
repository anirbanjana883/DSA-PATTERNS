Rat in a Maze


class Solution {
  public:
    // time 4 ^ (m * n)
    // space m * n 
    vector<string>result;
    bool isSafe(int i,int j,int n){
        
        return i>=0 && i<n && j>=0 && j<n; 
        
    }
    
    void solve(int i,int j,vector<vector<int>> &mat,int n,string&path){
            // if not safe abd xell value is zero then we can not go
           if(!isSafe(i,j,n) || mat[i][j]==0){
               return;
           }
            //   if we reach finalcell
           if(i==n-1 && j==n-1){
               
               result.push_back(path);
               return;
               
           }
        //   moving to next cell so make this cell value to 0
        mat[i][j]=0;
        // going to down
        path.push_back('D');
        solve(i+1,j,mat,n,path);
        path.pop_back();
        
         // going to up
        path.push_back('U');
        solve(i-1,j,mat,n,path);
        path.pop_back();
        
         // going to left
        path.push_back('L');
        solve(i,j-1,mat,n,path);
        path.pop_back();
        
         // going to right
        path.push_back('R');
        solve(i,j+1,mat,n,path);
        path.pop_back();
        
        // Reset the cell value to 1 during backtracking
        mat[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        string path="";
        if(n > 0) {
            solve(0, 0, mat, n, path); }
        return result;
    }
};