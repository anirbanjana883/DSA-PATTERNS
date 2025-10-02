do not have any exact question but it is very much important 
bcoz it have many veriant 

must do a dry run seeing striver vedio 
class Solution {
public:
    vector<int> printLIS(vector<int>& nums) {
        vector<int>dp(n,1);
        vector<int>hash(n); // keep track of the last idx for whicih we got max
        // len lis for this perticular idx
        int lastIdx=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIdx=i;
            }
        }
        // printing the LIS
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