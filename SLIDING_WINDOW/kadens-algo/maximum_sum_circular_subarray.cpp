918. Maximum Sum Circular Subarray

approach 1:

time complexity o(n^2)
space complexity o(1)

class Solution {
    public:
      int n;
      int maxSubarraySum(vector<int> &arr){
          int currSum=arr[0];
          int maxSum=arr[0];
          for(int i=1;i<n;i++){
              currSum=max(currSum+arr[i],arr[i]);
              maxSum=max(maxSum,currSum);
          }
          return maxSum;
      }
      void rotate(vector<int> &arr){
          int temp=arr[n-1];
          for(int i=n-2;i>=0;i--){
              arr[i+1]=arr[i];
          }
          arr[0]=temp;
      }
      int circularSubarraySum(vector<int> &arr) {
          n=arr.size();
          int result=INT_MIN;
          for(int i=0;i<n;i++){
              rotate(arr);
              int sum=maxSubarraySum(arr);
              result=max(result,sum);
          }
          return result;
      }
  };

approach 2:

time complexity o(n)
space complexity o(1)

algo :
1.find total sum 
2.finding minimum sum 
3.finding maximum sum 
4.circular sum = total sum-minimum sum

class Solution {
    public:
      int n;
      int findMxSum(vector<int> &arr){
          int currSum=arr[0];
          int mxSum=arr[0];
          for(int i=1;i<n;i++){
              currSum=max(currSum+arr[i],arr[i]);
              mxSum=max(mxSum,currSum);
          }
          return mxSum;
      }
      int findMnSum(vector<int> &arr){
          int currSum=arr[0];
          int mnSum=arr[0];
          for(int i=1;i<n;i++){
              currSum=min(currSum+arr[i],arr[i]);
              mnSum=min(mnSum,currSum);
          }
          return mnSum;
      }
      int circularSubarraySum(vector<int> &arr) {
          n=arr.size();
          int total_sum=accumulate(arr.begin(),arr.end(),0);
          int mn_sum=findMnSum(arr);
          int mx_sum=findMxSum(arr);
          int cir_sum=total_sum-mn_sum;
          
          return  mx_sum>0?max(mx_sum,cir_sum):mx_sum;
      }
  };