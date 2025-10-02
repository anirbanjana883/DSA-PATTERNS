540. Single Element in a Sorted Array

approach 1:

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        unordered_map<int,int>mp;
        int ans;
        for(auto it:arr){
            mp[it]++;
        }
        for(auto it:mp){
            if(it.second!=2) ans=it.first;
        }
        return ans;
    }
};

approach 2:

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        for(int i=0;i<n;i++){
            if(i==0){ // first element
                if(arr[i]!=arr[i+1]) return arr[i];
            }else if(i==n-1){ // last element 
                if(arr[i]!=arr[i-1]) return arr[i];
            }else { // somewhere in the mid 
                if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]) {
                    return arr[i];
                }
            }          
        }
        return -1;
    }
};

appproach 3:

notice one thing that 
a-odd e-even 
[1, 1, 2, 3, 3, 4, 5, 5, 6, 6]
 o  e  o  e  o  e  o  e  o  e

(even , odd) => left half and target is in right half
(odd , even ) => right half and target is in left half

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];        
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        int low=1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;
            // element found 
            if( arr[mid] !=arr[mid+1] && arr[mid] !=arr[mid-1]){
                return arr[mid];
            }
            // left half
            // even idx and next elemnt is same or
            // odd idx and prev element is asme 
            if((mid%2==0 && arr[mid]==arr[mid+1]) ||(mid%2==1 && arr[mid]==arr[mid-1] ) ){
                low=mid+1;
            }
            // right half
            // odd idx and next elemnt is same or
            // even idx and prev element is asme 
            else{
                high=mid-1;
            }     
        }
        return -1;
    }
};            