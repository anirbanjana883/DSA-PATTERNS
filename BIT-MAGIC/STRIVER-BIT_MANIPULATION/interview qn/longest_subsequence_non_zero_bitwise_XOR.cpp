3702. Longest Subsequence With Non-Zero Bitwise XOR

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // if xor of all element zero then we cant take all ans will be n - 1
        // for the above case if we exclude any element > 0 then xor become non zero
        // if xor of all emement i zero then we can just take whole array as subsequence ans = n 
        // if all element is zero then no subsequence
        int n = nums.size();
        int xor_of_all = 0;
        int or_of_all = 0;
        for(auto &x : nums){
            xor_of_all ^= x;
            or_of_all |= x;
        }
        if(!or_of_all) return 0; // all element are zero
        if(!xor_of_all) return n - 1;
        return n;
    }
};