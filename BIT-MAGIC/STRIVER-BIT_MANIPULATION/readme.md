Remember Few Things :

- (1 << n) = 2^n . Generalised : n << x = n * 2^x

- Similarly, n >> x = n / 2^x

- if ( (x & (1 << i)) == 0 ) , then ith bit of x is not set (i.e. 0) else it is set (i.e. 1)
  This will help you find subset using bit manipulation. 
  
- If we subtract a power of 2 number by 1 then all unset bits after the
  only set bit become set, and the set bit becomes unset.
  For example for 4 (100) and 16(10000), we get the following after subtracting 1 
      3 –> 011 
      15 –> 01111

   So, if( (n&(n-1)) == 0) , then n is even else it is odd