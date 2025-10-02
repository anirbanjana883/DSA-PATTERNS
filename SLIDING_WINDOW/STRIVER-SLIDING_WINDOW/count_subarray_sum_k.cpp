Subarrays with sum K

broute 

class Solution {
  public:
    // Time Complexity: O(n^2)  
    // Space Complexity: O(1)
    int cntSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n ; i++){
            int sum = 0;
            for(int j = i; j < n ; j++){
                sum += arr[j];
                if(sum == k) cnt ++;
            }
        }
        return cnt ;
    }
};

optimal

class Solution {
  public:
    // time o ( n )
    // space o ( 1 )
    int cntSubarrays(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int,int>mp;
        mp[0] = 1; // this step is crucial 
        int prefixSum = 0;
        int cnt = 0;
        for(int i = 0 ;i < n ; i++){
            prefixSum += arr[i];
            int toFind = prefixSum - k;
            if(mp.find(toFind) != mp.end()){
                cnt += mp[toFind];
            }
            mp[prefixSum] ++;
        }
        return cnt ;
    }
};