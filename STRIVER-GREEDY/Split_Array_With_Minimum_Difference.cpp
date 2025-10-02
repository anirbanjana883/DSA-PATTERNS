3698. Split Array With Minimum Difference



class Solution {
public:
    long long splitArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        long long lsum = 0, rsum = 0;

        // strictly increasing from left
        while (l < n - 1 && arr[l] < arr[l + 1]) 
            lsum += arr[l++];

        // strictly decreasing from right
        while (r > 0 && arr[r - 1] > arr[r]) 
            rsum += arr[r--];

        // single peak element
        if (l == r) {
            long long option1 = abs((lsum + arr[l]) - rsum);
            long long option2 = abs(lsum - (rsum + arr[l]));
            return min(option1, option2);
        } 
        // flat peak with two equal middle elements
        else if (r - l == 1 && arr[l] == arr[r]) {
            return abs(lsum - rsum);
        } 
        // invalid mountain
        else return -1;
    }
};
