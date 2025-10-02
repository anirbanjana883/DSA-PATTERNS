Check K-th Bit

broute force approach: 

convert the given no to binary and check if the k-th bit is set or not.

optimal approach: uisng bit manipulation

int both the case time complexity is O(1) and space complexity is O(1)

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // using left shift 
        if ((n & (1 << k)) != 0) return true; // set
        return false; // unset
    }
};

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        // using right shift 
        if (((n >> k) & 1) != 0) return true; // set
        return false; // unset
    }
};