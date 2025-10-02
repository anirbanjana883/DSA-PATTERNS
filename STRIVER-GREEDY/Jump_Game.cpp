55. Jump Game

class Solution {
public:
    // time o(n)
    // space o(1)
    bool canJump(vector<int>& nums) {
        // each array element can do jump max as array element 
        int n = nums.size();
        int mxIdx = 0;
        for(int i = 0; i < n ; i++){
            if(i > mxIdx) return false;
            mxIdx = max( mxIdx , i + nums[i]);
            if(i >= n-1) return true;
        }
        return true;
    }
};