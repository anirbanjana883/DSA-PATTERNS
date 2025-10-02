231. Power of Two

broute force approach : 

convert the number to binary 
count the number of 1's in the binary representation
if the count is 1 then it is a power of two
else it is not a power

optimal approach :

when we do n - 1 then the rightmost set bit becomes 0 and all the bits after it become 

n = 1 1 0 0 0 0
n - 1 = 1 0 1 1 1 1
if n & (n - 1) == 0 then it is a power of two
else it is not a power of two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};