260. Single Number III

class Solution {
public:
    // time o(2 * n)
    // space o( 1 )
    vector<int> singleNumber(vector<int>& nums) {
        // if we do xor of all the number 
        // the resultent will xor of the 2 number with appear ones
        // concept of bucket 
        int n = nums.size();
        // int xr = 0;
        // // 2^31 & ( -2^31 -1) not fit in int
        long long xr = 0;
        for(int i = 0;i < n ; i++) xr = xr ^ nums[i];
        // no_whos_rightMostBit_set = rmb;
        int rmb = (xr & -xr) & xr;
        int bucket1 = 0;
        int bucket2 = 0;
        for(int i = 0; i < n ; i++){
            // in each bucket all [paired] number will get cancelled
            if(nums[i] & rmb) bucket1 = bucket1 ^ nums[i];
            else              bucket2 = bucket2 ^ nums[i];
        }
        return { bucket1 , bucket2};
    }
};