Knapsack with Duplicate Items [gfg]

approach 1:recursn 

time complexity:exponential
space complexity:>>O(capacity) auxiliary space 

class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt,int idx, int capacity){
        // base case 
        if(idx==0){
            return int(capacity/wt[0])*val[0];
        }
        // explore all bthe cases
        int not_take=0+solve(val,wt,idx-1,capacity);
        int take =-1e9;
        if(wt[idx]<=capacity){
            take=val[idx]+solve(val,wt,idx,capacity-wt[idx]);
        }
        return max(take,not_take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        return solve(val,wt,n-1,capacity);
    }
};

approach 1:memoization 

time complexity:O(n*capacity) 
space complexity:O(capacity)+O(n*capacity) auxiliary recursn stack place .. 

class Solution {
  public:
    int solve(vector<int>& val, vector<int>& wt,int idx, int capacity,vector<vector<int>>&dp){
        // base case 
        if(idx==0){
            return int(capacity/wt[0])*val[0];
        }
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        // explore all bthe cases
        int not_take=0+solve(val,wt,idx-1,capacity,dp);
        int take =-1e9;
        if(wt[idx]<=capacity){
            take=val[idx]+solve(val,wt,idx,capacity-wt[idx],dp);
        }
        return dp[idx][capacity]=max(take,not_take);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return solve(val,wt,n-1,capacity,dp);
    }
};

approach 3: Tabulation 

time complexity:O(n*capacity) 
space complexity:O(n*capacity)

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int max_capacity) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(max_capacity+1,0));
        for(int i=0;i<=max_capacity;i++){
            dp[0][i]=int(i/wt[0])*val[0];
        }
        for(int idx=1;idx<n;idx++){
            for(int capacity=0;capacity<=max_capacity;capacity++){
                int not_take=0+dp[idx-1][capacity];
                int take =-1e9;
                if(wt[idx]<=capacity){
                    take=val[idx]+dp[idx][capacity-wt[idx]];
                }
                dp[idx][capacity]=max(take,not_take);
            }
        }
        return dp[n-1][max_capacity];
    }
};

approach 1:space optimisation 

time complexity:O(n*W) 
space complexity:O(2*capacity) auxiliary recursn stack place .. 

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int max_capacity) {
        int n=val.size();
        vector<int>prev(max_capacity+1,0),curr(max_capacity+1,0);
        for(int i=0;i<=max_capacity;i++){
            prev[i]=int(i/wt[0])*val[0];
        }
        for(int idx=1;idx<n;idx++){
            for(int capacity=0;capacity<=max_capacity;capacity++){
                int not_take=0+prev[capacity];
                int take =-1e9;
                if(wt[idx]<=capacity){
                    take=val[idx]+curr[capacity-wt[idx]];
                }
                curr[capacity]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[max_capacity];
    }
};


approach 1:more more space optimisation 

time complexity:O(n*W) 
space complexity:O(capacity) auxiliary recursn stack place .. 

because to calculate curr we just need one element of the previous 
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int max_capacity) {
        int n=val.size();
        vector<int>prev(max_capacity+1,0);
        for(int i=0;i<=max_capacity;i++){
            prev[i]=int(i/wt[0])*val[0];
        }
        for(int idx=1;idx<n;idx++){
            for(int capacity=0;capacity<=max_capacity;capacity++){
                int not_take=0+prev[capacity];
                int take =-1e9;
                if(wt[idx]<=capacity){
                    take=val[idx]+prev[capacity-wt[idx]];
                }
                prev[capacity]=max(take,not_take);
            }
        }
        return prev[max_capacity];
    }
};