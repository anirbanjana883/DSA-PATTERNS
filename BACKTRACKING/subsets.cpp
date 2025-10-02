78. Subsets  [when only unique element is present]
backtracking
[very imp]

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

take and not take approach 

class Solution {
public:
    // time complexity O(2^N)
    // space complexity O(N*(2^N))
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>&res,int i){
        if(i==nums.size()){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        solve(nums,ans,res,i+1);
        res.pop_back();
        solve(nums,ans,res,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,ans,res,0);
        return ans;
    }
};


