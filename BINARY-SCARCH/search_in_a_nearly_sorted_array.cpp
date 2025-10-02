Search in an almost Sorted Array

here the main difference with main binary search 
is if an elements correct position is i 
in nearly sorted Array we can found it in i-1 or i or i+1 position

class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          int n = arr.size();
          int low = 0, high = n - 1;
  
          while (low <= high) {
              int mid = low + (high - low) / 2;
  
              if (arr[mid] == target) return mid;
              if (mid - 1 >= low && arr[mid - 1] == target) return mid - 1;
              if (mid + 1 <= high && arr[mid + 1] == target) return mid + 1;
  
              if (arr[mid] > target) {
                  high = mid - 2;  // skip mid and mid-1
              } else {
                  low = mid + 2;   // skip mid and mid+1
              }
          }
  
          return -1;
      }
  };
