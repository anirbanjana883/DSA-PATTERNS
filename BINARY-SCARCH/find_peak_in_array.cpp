162. Find Peak Element [works for both single and multiple elemnts]


A peak element is an element that is strictly greater than its neighbors.
example 
Input: nums = [1,2,3,1]
Output: 2

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
         // since the array is in acsending orfer so 
        // the first element is greater then the second then it is the ans
        // because its previous element is -infinity
        if(arr[0]>arr[1]) return 0;
        // the last element is greater then its previous element  then it is the ans
         // because its next element is infinity
        if(arr[n-1]>arr[n-2]) return n-1;

        int low =1;
        int high=n-2;
        while(low<=high){
            int mid=low+(high-low);

            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]  )
            return mid;
            // left part is sorted and the peak is on right
           else if(arr[mid-1]<arr[mid] ){
                low=mid+1;
            }
            // right part is sorted and element is on left side
            else {
                high=mid-1;

            }
        } 
        return -1;
    }
};




for 2D array ->>>>
watch striver video again please 

class Solution {
public:
int max_element(vector<vector<int>>& arr,int n,int m,int col){
    int max_val=-1;
    int index=-1;
    // finding max element in any perticular column
    for (int i=0;i<n;i++){
        if(arr[i][col]>max_val){
            max_val=arr[i][col];
            index=i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid_col=low+(high-low)/2;
            //  we need to figure out in which row the max 
            // element is present for the perticular column
           int row=max_element(arr,n,m,mid_col);

            // now we have to cheak the max element in the row
            // is greater then the element on the left and right 
            //means in the same row next and previous column
            int left = mid_col-1>=0 ? arr[row][mid_col-1] : -1;
            int right = mid_col+1<m ? arr[row][mid_col+1] : -1;

            if (arr[row][mid_col]>left && arr[row][mid_col]>right){
                return {row,mid_col};
            }
            else if (left> arr[row][mid_col]){
                // peak elemen is on the left 
                high=mid_col-1;
            }else{
                low=mid_col+1;
            }

        }
        return {-1,-1};
    }
};