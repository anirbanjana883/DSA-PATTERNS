Set kth bit

broute force approach ;
convert it to binary and rech to that bit set it to 1

optimal approach :

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        return n | (1 << k);
    }
};
