494. Target Sum

this question is exactly similar of s1-s2=d problem
count partition with Given Difference

tabulation 

class Solution {
public:
    int countSubsequesnce(vector<int>& nums,int idx,int target){
        if(idx==0){
            // if one element and it is zero so if we take it or not take
            // in both the cases there will be no change
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }
        int not_pick=countSubsequesnce(nums,idx-1,target);
        int pick=0;
        if(nums[idx]<=target){
            pick=countSubsequesnce(nums,idx-1,target-nums[idx]);
        }
        return pick+not_pick;
    }
    int countPartitions(vector<int>& arr, int d) {
        int n=arr.size();
        int totalSum=0;
        for(auto &it:arr) totalSum+=it;
        if(totalSum-d<0 || (totalSum-d)%2) return 0;
        return countSubsequesnce(arr,n-1,(totalSum-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};