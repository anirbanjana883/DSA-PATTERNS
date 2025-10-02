Rod Cutting [gfg]

f(ind,n) => singnificance : till "ind " yoy can maximum price of " n "
approach 1:recursn 

time complexity:exponential
space complexity:o(N) auxiliary space (because same coin can be used many time ) so at worst this can be s.c

class Solution {
  public:
    int solve(vector<int> &price,int idx,int N){
        // base case 
        if(idx==0) return N*price[0];
        // explore ball ather posibilities
        int not_take=0+solve(price,idx-1,N);
        int take=INT_MIN;
        int rodLength=idx+1;// bcoz ind start from 0;
        if(rodLength<=N){
            take=price[idx]+solve(price,idx,N-rodLength); // we can take same rod length multiple time
        }
        return max(take,not_take);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        return solve(price,n-1,n);
    }
};

approach 1:memoization 

time complexity:O(n*N) 
space complexity:O(N)+O(n*N) auxiliary recursn stack place .. 

class Solution {
  public:
    int solve(vector<int> &price,int idx,int N,vector<vector<int>>&dp){
        // base case 
        if(idx==0) return N*price[0];
        if(dp[idx][N]!=-1) return dp[idx][N];
        // explore ball ather posibilities
        int not_take=0+solve(price,idx-1,N,dp);
        int take=INT_MIN;
        int rodLength=idx+1;// bcoz ind start from 0;
        if(rodLength<=N){2
            take=price[idx]+solve(price,idx,N-rodLength,dp); // we can take same rod length multiple time
        }
        return dp[idx][N]=max(take,not_take);
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(price,n-1,n,dp);
    }
};


approach 3: Tabulation 

time complexity:O(n*N) 
space complexity:O(n*N)

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        // base case
        for(int N=0;N<=n;N++) dp[0][N]=N*price[0];
        
        for(int idx=1;idx<n;idx++){
            for(int N=0;N<=n;N++){
                int not_take=0+dp[idx-1][N];
                int take=INT_MIN;
                int rodLength=idx+1;// bcoz ind start from 0;
                if(rodLength<=N){
                    take=price[idx]+dp[idx][N-rodLength]; // we can take same rod length multiple time
                }
                dp[idx][N]=max(take,not_take);
            }
        }
        return dp[n-1][n];
    }
};


approach 1:space optimisation 

time complexity:O(n*N) 
space complexity:O(2*N)

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>prev(n+1,0),curr(n+1,0);
        // base case
        for(int N=0;N<=n;N++) prev[N]=N*price[0];
        
        for(int idx=1;idx<n;idx++){
            for(int N=0;N<=n;N++){
                int not_take=0+prev[N];
                int take=INT_MIN;
                int rodLength=idx+1;// bcoz ind start from 0;
                if(rodLength<=N){
                    take=price[idx]+curr[N-rodLength]; // we can take same rod length multiple time
                }
                curr[N]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[n];
    }
};

approach 1: more more space optimisation 

time complexity:O(n*N) 
space complexity:O(N)


class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>prev(n+1,0);
        // base case
        for(int N=0;N<=n;N++) prev[N]=N*price[0];
        
        for(int idx=1;idx<n;idx++){
            for(int N=0;N<=n;N++){
                int not_take=0+prev[N];
                int take=INT_MIN;
                int rodLength=idx+1;// bcoz ind start from 0;
                if(rodLength<=N){
                    take=price[idx]+prev[N-rodLength]; // we can take same rod length multiple time
                }
                prev[N]=max(take,not_take);
            }
        }
        return prev[n];
    }
};

