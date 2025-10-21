2598. Smallest Missing Non-negative Integer After Operations

  to do a reminder 

  ( a % b ) = 
  (a % b + b) % b where a < 0 [ negative number ]


  class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto &num : nums){
            int r = ((num % value ) + value ) % value;

            mp[r]++;
        }

        int mex = 0;
        while(mp[(mex % value)] > 0){
            mp[(mex % value)]--;
            mex++;
        }
        return mex;
    }
};