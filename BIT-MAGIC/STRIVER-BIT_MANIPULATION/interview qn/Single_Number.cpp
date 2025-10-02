136. Single Number 

the ques tion can also come in 

Find the number that appears odd number of times

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // key concept a ^ a = 0 and a ^ 0 = a 
        // if we do xor of all the elements the number occuring 
        // only single time will remaining 
        int n = nums.size();
        int ans = 0;
        for (int i = 0 ;i < n ; i++){
            ans = ans ^ nums[i];
        }
        return ans ;
    }
};