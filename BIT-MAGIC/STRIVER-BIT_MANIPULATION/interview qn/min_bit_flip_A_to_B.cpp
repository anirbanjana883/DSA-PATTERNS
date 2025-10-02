2220. Minimum Bit Flips to Convert Number

class Solution {
public:
    // time o(31)
    // space o(1)
    int minBitFlips(int start, int goal) {
        // xor of 2 different element gives 1
        // step 1 : find which bits you need to flip
        // if we do xor of start and goal then the position 
        // n which 1 is present will have to flip
        int ans = start ^ goal;
        // now the number of set bit will be my answer done earlier
        return __builtin_popcount(ans); // count the number of 1s in ans
    }
};