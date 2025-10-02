78. Subsets

can also be done with power set checkthat code also 

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
        solve(nums,ans,res,i+1); // take (include element)
        res.pop_back();
        solve(nums,ans,res,i+1);// not take (excliude element)
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,ans,res,0);
        return ans;
    }
};