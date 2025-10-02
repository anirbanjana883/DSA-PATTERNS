33. Search in Rotated Sorted Array

*****IMP TIP********
if you get question envoving duplicate element then try to solve them as unique element


scarch in rotated sorted array {no duplicate}


approach 1:

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            //  element found
            if(arr[mid]==target) return mid;
            // left sorted
            if(arr[low]<=arr[mid]){
                // target present in the left side
                if(arr[low]<=target && arr[mid]>=target){
                    high=mid-1;
                }
                // target present in the right side
                else{
                    low=mid+1;
                }
            }
            // right sorted
            else{
                 // target present in the right side
                if(arr[mid]<=target && arr[high]>=target){
                    low=mid+1;
                }
                // target present in the left side
                else{
                    high=mid-1;
                }
            }
            
        }
        return -1;
    }
};

approach 2: 
we are finding the element on both isde of the pivot index 


class Solution {
public:
    int BinaryScarch(int low,int high,vector<int>& nums, int target){
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return mid;

            if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
    }
    int findPivotIdx(vector<int>& nums,int n){
        int low=0;
        int high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            // means there is definately leser element on right
            if(nums[mid]>nums[high]){
                low=mid+1;
                // that may be the ans;
            }else{
                high=mid;
            }
        }
        return high;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        // finding the pivot index
        int pivotIdx=findPivotIdx(nums,n);
        // if pivot index have the ans
        if(nums[pivotIdx]==target) return pivotIdx;
        // finding the target from the left side of pivot
        int idx=BinaryScarch(0,pivotIdx-1,nums,target);
        // if we found result from left then no need to 
        // find from the right
        if(idx!=-1) return idx;
        // find result from left side
        idx=BinaryScarch(pivotIdx+1,n-1,nums,target);
        return idx;
    }
};