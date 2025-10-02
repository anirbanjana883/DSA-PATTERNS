Minimum Platforms

broute force approach :

time complexity : O(n*n) 
space complexity : O(1)
we have to ffind the maximum no of intersection->

4 cases for intersectioning 

    arrive        depurture 
*                            *              case 1
           *                 *              case 2
*          *                                case 3
           *   *                            case 4

class Solution {
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    bool intersection(int a1, int d1, int a2, int d2) {
        return !(d1 < a2 || d2 < a1);
    }

    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n=arr.size();
        int maxCount=0;
        
        for(int i=0;i<n;i++){
            int count=1;
            for(int j=i+1;j<n;j++){
                if(intersection(arr[i],dep[i],arr[j],dep[j])){
                    count++;
                }
                
                maxCount=max(maxCount,count);
            }
        }
        return maxCount;
    }
};

time complexity o(n^2)
space complexity o(1)


optimised approach :
time complexity : O(2nlogn+2n) 
space complexity : O(1)
class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          int n=arr.size();
          
          sort(begin(arr),end(arr));
          sort(begin(dep),end(dep));
          
          int i=0;
          int j=0;
          
          int count=0;
          int maxCount=0;
          
          while(i<n){
              if(arr[i]<=dep[j]){
                  count+=1; // need platform
                  i++;
              }else{
                  count-=1; // free platform
                  j++;
              }
              maxCount=max(maxCount,count);
          }
          return maxCount;
      }
  };
  
  folow up question 2406. Divide Intervals Into Minimum Number of Groups
                    1419. Minimum Number of Frogs Croaking
