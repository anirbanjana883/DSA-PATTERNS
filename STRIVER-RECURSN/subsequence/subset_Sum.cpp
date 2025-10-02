Subset Sums

this is differnt from dp subset sum problem 

broute force approach - generating all subsets and then calculating their sum {power set}
time complexity - O(2^n * n)
space complexity - O(n) for recursion stack

optimal approach - using recursion to generate subsets and calculate their sums
time complexity - O(2^n)    
space complexity - O(2^n) for recursion stack

class Solution {
  public:
    /*
        time complexity - O(2^n) + o( nlogn) for sorting 
        space complexity - O(2^n) for recursion stack
    */
    int n ;
    vector<int>result;
    void solve(vector<int>& arr , int idx ,int sum){
        if ( idx == n){
            result.push_back(sum);
            return ;
        }
        // pick 
        solve(arr , idx + 1 , sum + arr[idx]);
        // not pick
        solve(arr , idx + 1 , sum);
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        n = arr.size();
        solve(arr , 0 , 0);
        sort(result.begin(), result.end());
        return result;
    }
};