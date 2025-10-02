45. Jump Game II

class Solution {
public:
    // time exponential
    int solve(vector<int>& nums,int ind , int jump){
        if( ind == nums.size() - 1) return jump;

        int mini = INT_MAX;
        for(int i = 1 ; i <= nums[ind] ;i++){
            mini = min (mini , solve(nums,ind + i, jump + 1));
        }
        return mini;
    } 
    int jump(vector<int>& nums) {
        return solve(nums,0,0);       
    }
};

class Solution {
public:
    // time o(n ^ 2)
    // space o(n ^ 2)
    int solve(vector<int>& nums,int ind , int jump,vector<vector<int>>&dp){
        if( ind == nums.size() - 1) return jump;

        if(dp[ind][jump] != -1) return dp[ind][jump];
        int mini = INT_MAX;
        for(int i = 1 ; i <= nums[ind] ;i++){
            mini = min (mini , solve(nums,ind + i, jump + 1 , dp));
        }
        return dp[ind][jump] = mini;
    } 
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n + 1,vector<int>(n + 1, -1));
        return solve(nums,0,0,dp);       
    }
};

class Solution {
public:
    // time O(n)
    // space O(1)
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;  // already at the end
        
        int jumps = 0;
        int current_end = 0;  // end of current jump range
        int farthest = 0;     // farthest position reachable in current jump
        
        for (int i = 0; i < n - 1; ++i) {  // no need to jump from last element
            farthest = max(farthest, i + nums[i]);
            
            if (i == current_end) {  // reached the end of current jump range
                jumps++;
                current_end = farthest;
                
                if (current_end >= n - 1) {  // can reach the end
                    break;
                }
            }
        }
        
        return jumps;
    }
};