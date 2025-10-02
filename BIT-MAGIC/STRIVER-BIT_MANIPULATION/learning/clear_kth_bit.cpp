clear the kth bit of a number

class Solution {
  public:
    int clearKthBit(int n, int k) {
        // place 0 at kth position and then do and opr 
        return n & ~(1 << k);
    }
};
