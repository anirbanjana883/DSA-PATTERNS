75. Sort Colors

broute force approach->

using any sorting algorithm

better approach ->

using count of each color and then sorting the colors based on count

class Solution {
public:
    void sortColors(vector<int>& nums) {   time complexity O(2N) -> O(N) space complexity O(1)
         int zero=0,one=0,two=0;
         for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;  //counting the number of zero
             else if(nums[i]==1) one++; //counting the numbers of 1
             else if(nums[i]==2) two++;  //counting the numbers of 2
         }
         for(int i=0;i<zero;i++){
            nums[i]=0; //placing the zero at the beginning
         }
          for(int i=zero;i<zero+one;i++){
            nums[i]=1; //placing the one at the middle
         }
          for(int i=zero+one;i<nums.size();i++){
            nums[i]=2; //placing the two at the end
         }
    }
};

optimal approach ---> [dutch national flag algorithm]
  link  https://www.youtube.com/watch?v=tp8JIuCXBaU&t=203s

we will be taking up three pointers low mid high

[o to low-1] -> 0  extreme left
[low to mid-1] -> 1
[mid to high-1] -> 2 extreme right

[0]       [low-1 ][low]     [mid-1][mid]     [high][high+1]    [n-1]
  0 0 0 0 0 0       1 1 1 1 1 1       ----------        2 2 2 2 2 
                                        0 or 1



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0,mid =0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){ //  first element in the mid is zero so it should be placed at the low
                swap(nums[low],nums[mid]);
                low++; //now at low there is zero so it is sorted
                mid++; //now at mid there is one so it is sorted
            }
            else if(nums[mid]==1){ //  first element in the mid is one 
                mid++; //no need of swap just move mid forword
            }
            else{  //  first element in the mid is two so it should be placed at the high
                swap(nums[mid],nums[high]);
                high--; // since high is sorted so no need to decrement
            }
        }
    }
};