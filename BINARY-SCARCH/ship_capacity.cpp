1011. Capacity To Ship Packages Within D Days

broute force
class Solution {
public:
     int req_day(vector<int>weights,int capacity){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                day=day+1; 
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
     }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0); // Calculate sum of all array element
        for(int capacity=low;capacity<=high;capacity++){
            int require_days=req_day(weights,capacity);
            if(require_days<=days) return capacity;
        }
        return -1;
    }
}

optimised approach ->binary scarch

class Solution {
public:
//  when we provide the capacity to this function 
// this function will tell me the days require to ship all pakages
     int req_day(vector<int>weights,int capacity){
        int day=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                day=day+1; 
                load=weights[i];
            }else{
                load+=weights[i];
            }
        }
        return day;
     }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0); // Calculate sum of all element in the array
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            // here mid is the capacity
            int require_days=req_day(weights,mid);
            if(require_days<=days){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};              