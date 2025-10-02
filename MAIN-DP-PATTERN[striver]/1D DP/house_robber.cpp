198. House Robber

approach 1:recursn

time complexity o(2^n);
space  complexity o(n) recursn stack place 

class Solution {
    public:
        int solve(vector<int>&nums,int idx){
            if(idx==0) return nums[idx];
            if(idx<0) return 0;
    
            int broke=nums[idx]+solve(nums,idx-2);
            int not_broke=0+solve(nums,idx-1);
            return max(broke,not_broke);
        }
        int rob(vector<int>& nums) {
           int n=nums.size();
            return solve(nums,n-1); 
        }
    };

approach 1: memoization  

time complexity o(n);
space  complexity o(n)+o(n) recursn stack place + dp array  

class Solution {
    public:
        int solve(vector<int>&nums,int idx,vector<int>&dp){
            if(idx==0) return nums[idx];
            if(idx<0) return 0;
            if(dp[idx]!=-1) return dp[idx];
    
            int broke=nums[idx]+solve(nums,idx-2,dp);
            int not_broke=0+solve(nums,idx-1,dp);
            return dp[idx]=max(broke,not_broke);
        }
        int rob(vector<int>& nums) {
           int n=nums.size();
           vector<int>dp(n+1,-1);
            return solve(nums,n-1,dp); 
        }
    };

approach 1: tabulation  

time complexity o(n);
space  complexity o(n);

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
    
            vector<int>dp(n,0);
            dp[0]=nums[0];
    
            for(int idx=1;idx<n;idx++){
                int broke=nums[idx];
                if(idx>1){
                    broke+=dp[idx-2];
                }
                int not_broke=0+dp[idx-1];
    
                dp[idx]=max(broke,not_broke);
            }
            return dp[n-1];
        }
    };

approach 4:space optimization 

time complexity o(n);
space  complexity o(1); 

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
    
            vector<int>dp(n,0);
            int prev=nums[0];
            int prev2=0;
    
            for(int idx=1;idx<n;idx++){
                int broke=nums[idx];
                if(idx>1){
                    broke+=prev2;
                }
                int not_broke=0+prev;
    
                int curr=max(broke,not_broke);
    
                prev2=prev;
                prev=curr;
            }
            return prev;
        }
    };