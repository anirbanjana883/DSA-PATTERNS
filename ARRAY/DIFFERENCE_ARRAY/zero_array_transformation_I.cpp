3355. Zero Array Transformation I

veriation of difference array problem 
broute force appproach : 
time complexity o(q*n)


difference array technique

time complexity o(q+n)
space complexity o(q+n)

#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n , 0); // Difference array
        
        // step 1: make differnece arrray using querty
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x=1;
            diff[l] += x;
            if(r+1<n){
                diff[r + 1] -= x; // Correctly decrement at r+1
            }
        }
        
        // step 2: find cumulativre sum on each index  
        int cumSum = 0;
        vector<int>result(n,0);
        for (int i = 0; i < n; i++) {
            cumSum += diff[i];
            result[i] = cumSum; // Apply prefix sum update
        }
        
        // check wheather the impact can make all the  element zero or not 
        for(int i=0;i<n;i++){
            if(result[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};
