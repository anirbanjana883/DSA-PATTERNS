Set the rightmost unset bit

class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        return n = (n | (n + 1));
    }
};