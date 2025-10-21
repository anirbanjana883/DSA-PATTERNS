3356. Zero Array Transformation II

approach 1: difference array technique

time complexity o(q*q)
space complexity o(n)

#include <vector>
using namespace std;

class Solution {
public: 
    int n;
    int q;
    
    bool checkDifferenceArrayTech(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n + 1, 0); // Extra space for handling boundary cases
        
        // Apply range update for the first `k` queries
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < n) {
                diff[r + 1] -= x; // Correct decrement
            }
        }

        // Compute actual values using prefix sum
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            diff[i] = cumSum;
            if (nums[i] -diff[i] > 0) { // Check if we reach zero array condition
                return false;
            }
        }     
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();
        
        // Check if all elements are initially zero
        auto lambda=[](int x){
            return x==0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)){
            return 0; // no query reqired 
        }
        
        // Replace binary search with a simple loop
        for (int i = 1; i <= q; i++) {  
            if (checkDifferenceArrayTech(nums, queries, i)) {
                return i; // Minimum queries required to make the array zero
            }
        }
        
        return -1;
    }
};

binary search approach :

time complexity o(log(q))
space complexity o(n)

#include <vector>
using namespace std;

class Solution {
public: 
    int n;
    int q;
    
    bool checkDifferenceArrayTech(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n + 1, 0); // Extra space for handling boundary cases
        
        // Apply range update for the first `k` queries
        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < n) {
                diff[r + 1] -= x; // Correct decrement
            }
        }

        // Compute actual values using prefix sum
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            diff[i] = cumSum;
            if (nums[i] -diff[i] > 0) { // Check if we reach zero array condition
                return false;
            }
        }     
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();
        
        // Check if all elements are initially zero
        auto lambda=[](int x){
            return x==0;
        };
        if(all_of(nums.begin(),nums.end(),lambda)){
            return 0; // no query reqired 
        }
        
        // replace loop by bs on ans
        // for (int i = 1; i <= q; i++) {  
        //     if (checkDifferenceArrayTech(nums, queries, i)) {
        //         return i; // Minimum queries required to make the array zero
        //     }
        // }
        
        int low=1;
        int high=q;
        int ans=-1;
        while(low <= high){
            int mid = low + (high - low) /2;
            if (checkDifferenceArrayTech(nums, queries, mid)) {
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;;
    }
};



