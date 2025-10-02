1482. Minimum Number of Days to Make m Bouquets
broute force approach  ->

class Solution {
public:
    // Helper function to find the minimum and maximum bloom days in the array
    void find_max_min(vector<int> arr, int &low, int &high) {
        for(auto it : arr) {
            low = min(low, it);  // Update low if current element is smaller
            high = max(high, it); // Update high if current element is larger
        }
    }
    
    // Function to check if it's possible to make 'm' bouquets with 'k' flowers each by day 'day'
    bool possible(vector<int> arr, int day, int m, int k) {
        int cnt = 0;          // Count of consecutive flowers that have bloomed by 'day'
        int no_of_b = 0;      // Count of bouquets that can be made
        
        for(auto it : arr) {
            if(it <= day) {   // If flower has bloomed by the given day
                cnt++;        // Increase consecutive bloom count
            } else {
                no_of_b += (cnt / k); // When sequence breaks, calculate bouquets from consecutive blooms
                cnt = 0;      // Reset consecutive count
            }
        }
        no_of_b += (cnt / k); // Add bouquets from the last sequence of consecutive blooms
        
        return (no_of_b >= m); // Return true if we can make at least 'm' bouquets
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        
        // Check if it's impossible to make required bouquets (not enough flowers)
        if (m * k > n) return -1; 
        
        int low = INT_MAX;  // Initialize low to maximum possible integer
        int high = INT_MIN; // Initialize high to minimum possible integer
        
        // Find the actual minimum and maximum bloom days
        find_max_min(bloomDay, low, high);
        
        // Linear search through all possible days from low to high
        for(int i = low; i <= high; i++) {
            // Check if we can make the bouquets by day 'i'
            if(possible(bloomDay, i, m, k)) {
                return i; // Return the first day that satisfies the condition
            }
        }
        
        return -1; // Return -1 if no day satisfies the condition (shouldn't happen due to initial check)
    }
};


optimised approach using binary scarch
 

class Solution {
public:
    void find_max_min(vector<int>arr,int &low,int &high){
        for(auto it:arr){
            low=min(low,it);
            high=max(high,it);
        }
    }
    bool possible(vector<int>arr,int day,int m,int k){
        int cnt=0;
        int no_of_b=0;
        for(auto it :arr){
            if(it<=day){
                cnt++;
            }else{
                no_of_b+=(cnt/k);
                cnt=0;
            }
        }
         no_of_b+=(cnt/k);
        return (no_of_b>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if (m>(n/k)) return -1; 
        int low=INT_MAX;
        int high=INT_MIN;
        find_max_min(bloomDay,low,high);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1; 
            }
            else{
               low=mid+1;
            }
        }
        return ans;
    }
};