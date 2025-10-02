491. Non-decreasing Subsequences

there should be no duplicate Subsequences
all number in subsequence will be non decreasing 
length of each subsequences must be 2


1.ith index include,exclude
2.curr element >=2 ->include
3.there should be set for each recursnn call 

class Solution {
public:
    int n;
    void backTrack(vector<int>& nums,int idx,vector<vector<int>>&result,vector<int>&curr){
        if(curr.size()>=2){
            result.push_back(curr);
        }
        unordered_set<int>st; // to check if the current element is pushed before or not
        for(int i=idx;i<n;i++){
            if((curr.empty() || nums[i]>=curr.back()) && (st.find(nums[i])==st.end())){
                curr.push_back(nums[i]); // taken
                backTrack(nums,i+1,result,curr); //explore
                curr.pop_back(); // removed

                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>result;
        vector<int>curr;
        backTrack(nums,0,result,curr);
        return result;
    }
}; 