368. Largest Divisible Subset

subset ?? 1 . not continiouis  2. no oder maintainded

how it is similar to print LIS ?
remember the if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }

{ nums[i]>nums[prev] } if we change this to { nums[j]%nums[i] == 0 }  boom  💥

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
         vector<int>dp(n,1);
        vector<int>hash(n); // keep track of the last idx for whicih we got max
        // len lis for this perticular idx
        int lastIdx=0;
        int maxi=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                // little bit change here 
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIdx=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIdx]);
        while(hash[lastIdx]!=lastIdx){
            lastIdx=hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        reverse (temp.begin(),temp.end());
        return temp;
    }
};