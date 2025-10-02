Geeks Training gfg

approach 1: recursive aproach 

class Solution {
    public:
      int solve(vector<vector<int>>& arr,int day,int last){
          // base case 
          if(day==0){
              int maxi=0;
              
              for(int i=0;i<3;i++){
                  if(i!=last){
                      maxi=max(maxi,arr[0][i]);
                  }
              }
              return maxi;
          }
          
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last){
                  int points=arr[day][i]+solve(arr,day-1,i);
                  maxi=max(maxi,points);
              }
          }
          return maxi;
      }
      int maximumPoints(vector<vector<int>>& arr) {
          // Code here
          int n=arr.size();
          int last=3;
          
          return solve(arr,n-1,last);
      }
  };

appproach 2:memoization

since for each day there is 4 options so we need n*4 dp

time complexity O(n*4*3)
space complexity O(n*4)+o(n) 

class Solution {
    public:
  //   since two parameteri schanging here so we need 2d dp
      int solve(vector<vector<int>>& arr,int day,int last,vector<vector<int>>&dp){
          // base case 
          if(day==0){
              int maxi=0;
              
              for(int i=0;i<3;i++){
                  if(i!=last){
                      maxi=max(maxi,arr[0][i]);
                  }
              }
              return maxi;
          }
          
          if(dp[day][last]!=-1){
              return dp[day][last];
          }
          
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last){
                  int points=arr[day][i]+solve(arr,day-1,i,dp);
                  maxi=max(maxi,points);
              }
          }
          return dp[day][last]=maxi;
      }
      int maximumPoints(vector<vector<int>>& arr) {
          // Code here
          int n=arr.size();
          int last=3;
          vector<vector<int>>dp(n,vector<int>(4,-1));
          return solve(arr,n-1,last,dp);
      }
  };


appproach 4: tabulation 

base case in all the cases 
 [0][0],[0][1],[0][2],[0][3] base case will be executed no matter what the value of last

 dp[0][0]=max(arr[0][1],arr[0][2]);
 dp[0][1]=max(arr[0][2],arr[0][3]);
 dp[0][2]=max(arr[0][1],arr[0][3]);
 dp[0][3]=max(arr[0][1],arr[0][2],arr[0][3]);

 time complexity O(n*4*3)
space complexity O(n*4)

 code 
 class Solution {
   public:
     int maximumPoints(vector<vector<int>>& arr) {
         // Code here
         int n=arr.size();
         vector<vector<int>>dp(n,vector<int>(4,0));
        //  similarity with recursn dp[day][last]
         // base case
         dp[0][0]=max(arr[0][1],arr[0][2]);
         dp[0][1]=max(arr[0][0],arr[0][2]);
         dp[0][2]=max(arr[0][0],arr[0][1]);
         dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
         
         for(int day=1;day<n;day++){
             // for each day there is 4 option
             for(int last=0;last<4;last++){
                 dp[day][last]=0; // from the recursn we want to calculate this 
                 
                 for(int task=0;task<3;task++){
                     if(task!=last){
                         int points=arr[day][task]+dp[day-1][task];
                         dp[day][last]=max(dp[day][last],points);
                     }
                 }
             }
         }
         return dp[n-1][3];
     }
 };

appproach 4: space optimisation 

time complexity O(n*4*3)
space complexity O(4)=o(1)

notice onething to calculate any row we just need the previous row 
not all the previous rows so no need of dp array 
insted we can take a 4 size temporay array for atoring 

class Solution {
    public:
      int maximumPoints(vector<vector<int>>& arr) {
          // Code here
          int n=arr.size();
         vector<int>previous(4,0);
          
          // base case
          previous[0]=max(arr[0][1],arr[0][2]);
          previous[1]=max(arr[0][0],arr[0][2]);
          previous[2]=max(arr[0][0],arr[0][1]);
          previous[3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
          
          for(int day=1;day<n;day++){
              // for each day there is 4 option
              vector<int>temp(4,0);
              
              for(int last=0;last<4;last++){
                  temp[last]=0; // from the recursn we want to calculate this 
                  
                  for(int task=0;task<3;task++){
                      if(task!=last){
                          temp[last]=max(temp[last],arr[day][task]+previous[task]);
                      }
                  }
              }
              previous=temp;
          }
          return previous[3];
      }
  };
