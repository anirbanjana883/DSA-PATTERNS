930. Binary Subarrays With Sum

class Solution {
public:
    // time o (n^2)
    // space o (1)
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            int sum = 0;
            for(int j = i; j < n ; j++){
                sum += nums[j];
                if(sum == goal) cnt ++;
            }
        }
        return cnt ;
    }

};

// Optimized approach 
class Solution {
public:
    // time o(2 * n)
    // space o (1)
    int n;
    int helper(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){ // sum <= goal
                sum -= nums[l];
                l += 1;
            }
            cnt += r - l + 1;
            r ++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        n = nums.size();
        return helper(nums,goal) - helper(nums,goal - 1);
    }
};