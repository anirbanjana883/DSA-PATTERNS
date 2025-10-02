clear rightmost set bit in a number

note one thing that if we do n -1 of a number then it will clear the rightmost set bit of that number
// for example 6 = 110 in binary and 6 - 1 = 5  
// 5 = 101 in binary
class Solution {
  public:
    int clearRightmostBit(int n) {
        // Write Your Code here
        return n & (n-1);
    }
};