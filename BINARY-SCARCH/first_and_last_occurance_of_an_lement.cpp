34. Find First and Last Position of Element in Sorted Array

approach 1: linera iteration on both side

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target) {
                res[0]=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
           if(nums[i]==target) {
                res[1]=i;
                break;
            }
        }
        return res;
    }
};

approach 2: binary search approach 

class Solution {
public:
    int lower_bound(vector<int>& arr, int k,int n) {
        int low = 0, high = n- 1;
        int ans = n;
        while (low <= high) {a
            int mid = low + (high - low) / 2;
            if (arr[mid] >= k){
                ans = mid;
                 high = mid - 1;
            }
          else {
             low = mid + 1;
              }
        }
        return ans;
    }

   int upper_bound(vector<int>& arr, int k,int n) {
        int low = 0, high = n- 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > k){
                ans = mid;
                 high = mid - 1;
            }
          else {
             low = mid + 1;
              }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& arr, int k) {
        int lb = -1;
        int n=arr.size();
        lb = lower_bound(arr, k,n);
        if (lb==n|| arr[lb]!=k)
            return {-1, -1};
        return {lb, upper_bound(arr, k,n)-1};
    }
};