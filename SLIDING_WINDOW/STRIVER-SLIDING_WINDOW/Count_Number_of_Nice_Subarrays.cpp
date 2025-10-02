1248. Count Number of Nice Subarrays

❤️❤️❤️❤️ how to convert this question to - 930. Binary Subarrays With Sum

class Solution {
public:
    // time o(3 * n)
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
    int numberOfSubarrays(vector<int>& nums, int k) {
        // make all add number to 1 
        // and all even number to 0;
        // then subarray sum = k is Binary Subarrays With Sum = k
        n = nums.size();
        for(int i = 0; i < n ; i++){
            if(nums[i] % 2 == 1) nums[i] = 1;
            else nums[i] = 0;
        }
        return helper(nums,k) - helper(nums,k - 1);
    }
};