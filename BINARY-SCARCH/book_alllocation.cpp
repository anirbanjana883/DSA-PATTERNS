Allocate Minimum Pages


 broute force approach -> normal linear scarch o(n^2)
 class Solution {
    public: 
    int if_possible(vector<int>arr,int k,int max_page){
        int pages=0;
        int cnt_student=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if((pages+arr[i])<=max_page){
                pages+=arr[i];
            }else{
                pages=arr[i];
                cnt_student++;
            }
        }
        return cnt_student;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n<k) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(), arr.end(), 0);
         int ans=high;
        for(int i=low;i<=high;i++){
            if(if_possible(arr,k,i)<=k){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
    optimized approach -> using binary scarch o(nlog n)

   int if_possible(vector<int>arr,int max_page){
      int pages=0;
      int cnt_student=1;
      int n=arr.size();
      for(int i=0;i<n;i++){
          if((pages+arr[i])<=max_page){
              pages+=arr[i];
          }else{
              pages=arr[i];
              cnt_student++;
          }
      }
      return cnt_student;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n<k) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(), arr.end(), 0);
         int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(if_possible(arr,mid)<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }