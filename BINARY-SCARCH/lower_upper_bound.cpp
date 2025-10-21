34. Find First and Last Position of Element in Sorted Array

lower bound :
Find the first element that is not less than x (i.e., >= x).
// auto it = lower_bound(v.begin(), v.end(), x);  // First element >= x

upper bound :
Find the first element that is strictly greater than x (i.e., > x).
auto it = upper_bound(v.begin(), v.end(), x);  // First element > x

int lower_bound(vector<int>& arr, int k,int n) {
        int low = 0, high = n- 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= k){   => condition of lower bound
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
            if (arr[mid] > k){  => condition of lower bound
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

    
another methode bY cpp stl

class Solution {
public:
    int find_lower_bound(vector<int>& arr, int k,int n) {
       int lb= lower_bound(arr.begin(),arr.end(),k)-arr.begin();
              return lb;
    }
int find_upper_bound(vector<int>& arr, int k,int n) {
       int ub= upper_bound(arr.begin(),arr.end(),k)-arr.begin();
              return ub;
    }

    vector<int> searchRange(vector<int>& arr, int k) {
        int lb = -1;
        int n=arr.size();
        lb = find_lower_bound(arr, k,n);
        if (lb==n|| arr[lb]!=k)
            return {-1, -1};
        return {lb, find_upper_bound(arr, k,n)-1};
    }
};