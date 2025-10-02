Count Primes In Range

approach 1 :

// User function Template for C++

class Solution {
  public:
    /*
        Function	     Time Complexity	Space Complexity
        sieve(n)	       O(n log log n)	O(n)
        countPrimes(L, R)	O(R log log R)	O(R)
        
        */
    vector<int> sieve(int n) {
        // code here
        vector<int>prime(n+1 , 1);
        vector<int>result;
        for(int i = 2 ;i * i <= n ; i++){
            if(prime[i] == 1){
                for(int j = i * i; j <= n ; j = j + i){
                    prime[j] = 0; // mark all multiple as zero 
                }
            }
        }
        for( int i = 2 ;i < prime.size() ; i++){
            if(prime[i]) result.push_back(i);
        }
        return result;
    }
    int countPrimes(int L, int R) {
        // code here
        vector<int>prime = sieve(R);
        int cnt = 0;
        
        for (int num : prime) {
            if (num >= L && num <= R) {
                cnt++;
            }
        }
        return cnt ;
    }
};