300. Longest Increasing Subsequence

time complexity o(nlogn)
space complexity o(n)

int ind=lower_bound(temp.begin(),temp.end(),nums[i]-temp.begin());
find the actual index of nums[i] or the first index greater than nums[i] in temp

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // the temp produced in this process is never actual LIS
        // it just the rplica of the LIS
        int n=nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};