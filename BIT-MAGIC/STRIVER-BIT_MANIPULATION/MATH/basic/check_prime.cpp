Prime Number

class Solution {
        // time o( n )
  public:
    // correct defination of prime numbee
    // a number that have divisor of 1 and itshelf 
    // and total no of divisor is 2
    bool isPrime(int n) {
        int cnt = 0;
        for(int i = 1;i <= n ; i++){
            if(n % i == 0) cnt ++;
        }
        return cnt == 2;
    }
};


class Solution {
        // time o( sqrt(n) )
        // space o ( 1 )
  public:
    // correct defination of prime numbee
    // a number that have divisor of 1 and itshelf 
    // and total no of divisor is 2
    bool isPrime(int n) {
        if( n <= 1) return false;
        int cnt = 0;
        for(int i = 1;i * i <= n ; i++){
            if(n % i == 0) {
                cnt ++;
                if(n % i != i) {
                    cnt ++;
                }
            }
            if( cnt > 2) break;
        }
        return cnt == 2;
    }
};
