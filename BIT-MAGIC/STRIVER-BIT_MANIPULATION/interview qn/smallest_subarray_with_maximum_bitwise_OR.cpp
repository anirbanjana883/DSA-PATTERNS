2411. Smallest Subarrays With Maximum Bitwise OR

class Solution {
public:
    // time o ( n * 32)
    // space o( n )
    vector<int> smallestSubarrays(vector<int>& nums) {
        //  till how much we have to take or such that 
        // its 0th bit  , 1th bit .. get set
        int n = nums.size();
        // setBitIdx [j] = 3 we need to go till index 3 to set jth bit
        vector<int>setBitIdx(32 , -1);
        vector<int>result(n);
        for(int i = n - 1; i >= 0 ; i--){
            int endIdx = i;
            for(int j = 0 ; j < 32 ; j++){
                if((nums[i] & (1 << j)) == 0){ // check if jth bit set or not 
                    if(setBitIdx[j] != -1){
                        endIdx = max( endIdx , setBitIdx[j]);
                    }
                }else{
                    setBitIdx[j] = i;
                }
            }
            result[i] = endIdx - i + 1;
        }
        return result;
    }
}; 