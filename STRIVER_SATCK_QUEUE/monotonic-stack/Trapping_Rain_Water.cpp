42. Trapping Rain Water

broute force approach : 

class Solution {
public:
    // time o ( 3 * n)
    // space o ( 2 * n)
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefixMax(n, 0);
        vector<int> suffixMax(n, 0);

        // Calculate prefixMax (left max for each position)
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }

        // Calculate suffixMax (right max for each position)
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }

        // Calculate trapped water
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            trappedWater += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return trappedWater;
    }
};

optimised appsroach : space optimised 

class Solution {
public:
    // time o ( n)
    // space o ( 1 )
    int trap(vector<int>& arr) {
        int n = arr.size();
        int trappedWater = 0;
        int l = 0;
        int r = n - 1;
        int lmax = 0;
        int rmax = 0;
        while ( l < r) {
            if(arr[l] <= arr[r]){
                if( lmax > arr[l]){
                    trappedWater += lmax - arr[l];
                }else{
                    lmax = arr[l]; // update lamx 
                }
                l = l + 1;
            }else{
                if( rmax > arr[r]){
                    trappedWater += rmax - arr[r];
                }else{
                    rmax = arr[r]; // update ramx 
                }
                r = r - 1;
            }
        }
        return trappedWater;
    }
};