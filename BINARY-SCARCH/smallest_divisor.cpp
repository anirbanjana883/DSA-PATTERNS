1283. Find the Smallest Divisor Given a Threshold->
brout force approach

class Solution {
public:
    void find_max_min(vector<int>arr,int &low,int &high){
        for(auto it:arr){
            low=min(low,it);
            high=max(high,it);
        }
    }
    int div_sum(vector<int>nums,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(static_cast<double>(nums[i])/divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=1;
        find_max_min(nums,low,high);
        for(int i=low;i<=high;i++){
            if(div_sum(nums,i)<=threshold){
                return i;
            }
        }
        return -1;
    }
};
optimised approach using binary scarch
class Solution {
public:
    int div_sum(vector<int>nums,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)(nums[i])/(double)divisor);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(div_sum(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};