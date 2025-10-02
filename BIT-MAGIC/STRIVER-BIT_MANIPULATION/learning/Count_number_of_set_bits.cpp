191. Number of 1 Bits 

no shortcart pure broute force 

very important ::
how to check if a number is odd or even
if n & 1 == 1 then n is odd
if n & 1 == 0 then n is even

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while( n > 1){
            if ( (n % 2) == 1) cnt ++;
            n /= 2;
        }
        return n == 1 ? cnt + 1 : cnt;
    }
};

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while( n > 1){
            cnt += n & 1;
            n = n >> 1;
        }
        return n == 1 ? cnt + 1 : cnt;
    }
};

class Solution { // STL 
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};

class Solution {
public:
    // time no of set bit 
    int hammingWeight(int n) {
        int cnt = 0;
        while( n != 0){
            n = n & (n - 1 ); // each time right most set bit vanished
            cnt ++;
        }
        return cnt ;
    }
};