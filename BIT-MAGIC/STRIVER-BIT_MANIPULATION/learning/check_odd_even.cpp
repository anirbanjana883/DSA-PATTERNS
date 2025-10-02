check odd or even using bit manipulation

class Solution {
  public:
    bool isEven(int n) {
        // code here
        return n & 1 == 1 ? false : true;
    }
};