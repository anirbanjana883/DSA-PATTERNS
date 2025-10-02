416. Partition Equal Subset Sum

verialtion of subset sum equals to k::
see how this problem is equivalant to the subset sum problem ...

subset1      subset2
subsetSum1  subsetSum2
totalSum-subset1=subsetSum1
[subsetSum=(totalSum)/2]

approach 1:recursn 

time complexity:O(2^n) 
space complexity:O(n) auxiliary recursn stack place .. 

{same ans previous}

approach 2:memoization  

time complexity:O(n*sum) 
space complexity:O(n*sum)+o(n)

{same ans previous}

approach 3:tabulation  

time complexity:O(n*sum) 
space complexity:O(n*sum)

{same ans previous}

approach 4:space optimization  

time complexity:O(n*sum) 
space complexity:O(1)

class Solution {
    public:
        bool isSubsetSum(vector<int>& arr, int sum) {
              // code here 
              int n=arr.size();
              vector<bool>prev(sum+1,false),curr(sum+1,false);
              prev[0]=curr[0]=true;
              if(arr[0]<=sum) prev[arr[0]]=true;
              for(int ind=1;ind<n;ind++){
                  for(int target=1;target<=sum;target++){
                      bool exclude=prev[target];
                      bool include=false;
                      if(arr[ind]<=target){
                          include=prev[target-arr[ind]];
                      }
                      
                      curr[target]=exclude || include;
                  }
                  prev=curr;
              }
              return prev[sum];         
        }
    
        bool canPartition(vector<int>& nums) {
            int totalSum=0;
            for(auto &it:nums){
                totalSum+=it;
            }
    
            if(totalSum%2!=0) return false;
            int target =totalSum/2;
            return isSubsetSum(nums,target);
        }
    };