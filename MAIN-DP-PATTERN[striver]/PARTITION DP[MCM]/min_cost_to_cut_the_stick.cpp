1547. Minimum Cost to Cut a Stick

approach 1:recursn 
t.c - o(2^c*c) exponential
s.c - o(c)

class Solution {
public:
    int solve(vector<int>& cuts,int i,int j){
        // base case 
        if(i>j) return 0;
        // explore all ather psobilities 
        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int cost = cuts[j+1]-cuts[i-1]+
                        solve(cuts,i,idx-1)+
                        solve(cuts,idx+1,j);
            mini=min(mini,cost);
        }
        return mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // n - length of wooden stick 
        // c - size of the cut array 
        int c=cuts.size();
        // for our ease we are modifying the cut array 
        cuts.push_back(n); // push at last 
        cuts.insert(cuts.begin(),0); // insert at last 
        sort(cuts.begin(),cuts.end());
        return solve(cuts,1,c);
    }
};


approach 2:memoization 
t.c - o(c^2*c) 
s.c - o(c^2)+o(c)

class Solution {
public:
    int solve(vector<int>& cuts,int i,int j,vector<vector<int>>&dp){
        // base case 
        if(i>j) return 0;
        // explore all ather psobilities 
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int cost = cuts[j+1]-cuts[i-1]+
                        solve(cuts,i,idx-1,dp)+
                        solve(cuts,idx+1,j,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // n - length of wooden stick 
        // c - size of the cut array 
        int c=cuts.size();
        // for our ease we are modifying the cut array 
        cuts.push_back(n); // push at last 
        cuts.insert(cuts.begin(),0); // insert at last 
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return solve(cuts,1,c,dp);
    }
};

approach 2:tabulation 
t.c - o(c^2*c) 
s.c - o(c^2)

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // n - length of wooden stick 
        // c - size of the cut array 
        int c=cuts.size();
        // for our ease we are modifying the cut array 
        cuts.push_back(n); // push at last 
        cuts.insert(cuts.begin(),0); // insert at last 
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>>dp(c+1,vector<int>(c+1,0)); this can lead to IOB
        //  idx-1 and idx+1 
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        // no need to write base case
        for(int i=c;i>=1;i--){
            for(int j=0;j<=c;j++){
                if(i>j) continue;
                int mini=INT_MAX;
                for(int idx=i;idx<=j;idx++){
                    int cost = cuts[j+1]-cuts[i-1]+
                               dp[i][idx-1]+
                               dp[idx+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};