992. Subarrays with K Different Integers

class Solution {
public:
    // time o (n ^ 2)
    // space o ( n )
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int cnt = 0;
        for(int i =0 ; i < n ; i ++){
            for(int j = i ; j < n ; j++){
                mp[nums[j]] ++;
                if( mp.size() == k) cnt++; 
                if(mp.size() > k) break;
            }
            mp.clear();
        }
        return cnt ;
    }
};

class Solution {
public:
    // time o (2 * n)
    // space o ( n)
    int n ;
    int helper (vector<int>& nums, int k){
        // this funvtion find subarray staiisfy condn <= k
        int l = 0;
        int r = 0;
        int cnt = 0;
        unordered_map<int , int>mp;
        while( r < n){
            mp[nums[r]] ++;
            // keep on shrinking till get valid subarray
            while(mp.size() > k){
                mp[nums[l]] --;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt += r - l + 1;
            r ++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        n = nums.size();
        return helper(nums,k) - helper(nums,k - 1);
    }
};