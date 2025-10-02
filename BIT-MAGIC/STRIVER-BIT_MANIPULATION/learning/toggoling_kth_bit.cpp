toggling the ith bit of a number

class Solution {
  public:
    int togglekthBits(int n, int k) {
        // code here
        (n ^ ( 1 << k));
        return n;
    }
};

follow up question: Toggle bits in the given range

class Solution {
public:
    int toggleBits(int n, int l, int r) {
        l--;
        while(l<r){
           n= (n^(1<<l));
            l++;
        }
        return n;
    }
};