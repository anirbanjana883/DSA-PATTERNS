137. Single Number II

approach 1: Using Bit Manipulation
class Solution {
public:
    //  time o( n * 32)
    // space o ( 1 )
    int singleNumber(vector<int>& nums) {
        // for each bit let( 0th 1th 2nd ..) we will count 
        // how many set bit is there
        int n = nums.size();
        int ans = 0;
        for(int bitIdx = 0 ; bitIdx < 32 ; bitIdx ++){ // 0 1 2 3 ....31
            int cnt = 0;
            for (int i = 0; i < n ;i ++){ // down word
                if (nums[i] & ( 1 << bitIdx)) cnt ++;
            }
            if( cnt % 3 == 1){ // set that bit
                ans = ans | ( 1 << bitIdx);
            }
        }
        return ans;
    }
};

// approach 2: Using Sorting
class Solution {
public:
    //  time o( nlogn + n/3)
    // space o ( 1 )
    int singleNumber(vector<int>& nums) {
        /*
        1 1 1 2 2 2 3 4 4 4    
          |
        1 1 1 2 2 2 3 4 4 4    
                |
        1 1 1 2 2 2 3 4 4 4    
                      |
        */
        int n = nums.size();
        sort( nums.begin() , nums.end());
        for (int i = 1 ;i < n; i = i + 3){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        // if not find in the loop then the last element will always be ans 
        return nums[n-1];
    }
};

approach 3: 

concept of bucket 

class Solution {
public:
    //  time o( n )
    // space o ( 1 )
    int singleNumber(vector<int>& nums) {
        /*
       nums[i] will go to ones if not in twos
       nums[i] will go to twos if not in ones
       nums[i] will go to three if not in tows
       */
        int n = nums.size();
        int ones = 0;
        int twos = 0;
        for(int i =0 ;i < n; i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones ;
    }
};