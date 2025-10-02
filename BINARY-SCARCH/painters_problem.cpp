The Painters Partition Problem-II gfg 
410. Splite Array Largest Sum  leetcode

 both are same problem exactly same problem

optiimized approach -> for The Painters Partition Problem-II

class Solution {
  public:
    long long minTime(vector<int>& arr, int k) {
      
        int n=arr.size();
        long long start=0,end=0,ans,mid;
        for(int i=0;i<n;i++)
        {
            if(start<arr[i])
            start=arr[i];
            end+=arr[i];
            
        }
        while(start<=end)
        {
            mid=start+(end-start)/2;
            long long boards=0,count=1;
            for(int i=0;i<n;i++)
            {
                boards+=arr[i];
                if(boards>mid)
                {
                    count++;
                    boards=arr[i];
                }
            }
            if(count<=k)
            {
                ans=mid;
                end=mid-1;
                
            }
            else{
                start=mid+1;
            }
           
        }
        
       return ans;
    }
};

optiimized approach -> for  Splite Array Largest Sum

class Solution {
public:
int if_possible_sum(vector<int>arr,int possible_sum){
      int n=arr.size();
      int subarray_count=1;
      int max_sum=0;
      for(int i=0;i<n;i++){
        if((max_sum+arr[i])<=possible_sum){
            max_sum+=arr[i];
        }  else{
            subarray_count++;
            max_sum=arr[i];
        }
      }
      return subarray_count;
  }
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(if_possible_sum(arr,mid)<=k){
                ans=mid;
                // have to find more smaller element
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
