81. Search in Rotated Sorted Array II 

*****IMP TIP********
if you get question envoving duplicate element then try to solve them as unique element


scarch in rotated sorted array {duplicate present}


approach 1:

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
         int mid=low+(high-low)/2;
                     //  element found
                     if(arr[mid]==target) return 1;
        //  for duplicate elemnt present in the rotated array
        // shrink the array untill array become out of duplication
            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                low++;
                high--;
            }
           else{
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
        }
        return 0;
    }
};