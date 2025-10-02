1539. Kth Missing Positive Number

broute force 1.

time complexity O(high) 
space complexity O(n+high)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;       
        int high=*max_element(arr.begin(),arr.end());
        vector<int>missing;
        for(auto it:arr){
            mp[it]++;
        } 
        for(int i=1;i<=high;i++){
            if(mp.find(i)==mp.end()){
                 missing.push_back(i);
            }
        }

        if(k<=missing.size())
        return missing[k-1];
        // Input: arr[] = [1, 2, 3], k = 2
        // for this kind of case  
        // Input: arr[] = [1, 2, 3], k = 2
        // Output: 5
        // Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.
        else
        return high+k-missing.size();
    }
};

broute force 2.

time complexity O(n) 
space complexity O(1)

 class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        if(k<arr[0]) return k;
        for(int i=0;i<n;i++){
            if(arr[i]<=k) k++;
            else break;
        }
        return k;
    }
};


optimal appproach -> binary scarch;

Time Complexity: O(log n)
Space Complexity: O(1)

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        // binary search here 
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing_in_left=arr[mid]-(mid+1);
            if(missing_in_left<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low+k;
    }
};
