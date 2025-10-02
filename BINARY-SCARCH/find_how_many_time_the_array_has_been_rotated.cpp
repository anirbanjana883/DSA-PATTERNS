Find Kth Rotation

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start=0;
        int end=arr.size()-1;
        int index=0;
        int ans =arr[0];
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]>=arr[0]){
                start=mid+1;
            }
            else{
                ans=arr[mid];
                index=mid;
                end=mid-1;
            }
        }
        return index;
    }
};