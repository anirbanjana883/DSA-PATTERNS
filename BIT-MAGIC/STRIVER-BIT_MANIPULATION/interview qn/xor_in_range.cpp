Find XOR of numbers from L to R.

approach 1 : iterating through the vector and calculating the XOR
Time Complexity: O(n)
Space Complexity: O(1)

appraoch 2 : 

n = 1  1  = 1
n = 2  1 ^ 2 = 3
n = 3  1 ^ 2 ^ 3 = 0
n = 4  1 ^ 2 ^ 3 ^ 4 = 4

n = 5  1 ^ 2 ^ 3 ^ 4 ^ 5 = 1
n = 6  1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 = 7
n = 7  1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 = 0
n = 8  1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

n = 9  1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 = 1

so finding the XOR from 1 to n can be done in O(1) time complexity

int xor_upto_n(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0; // n % 4 == 3
}

follow up question is - > find from l to R

class Solution {
  public:
    // time o(1)
    // space o(1)
    int xor_upto_n(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0; // n % 4 == 3
    }
    int findXOR(int l, int r) {
        // observing the pattern we can see something 
        // we will find xor of 1 to l = x
        // we will find xor of 1 to r = y 
        // ans = x ^ y
        
        int x = xor_upto_n(l-1);
        int y = xor_upto_n(r);
        return x ^ y;
    }
};