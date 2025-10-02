Prime Factors

approach 1: Brute Force
class Solution { // optimesd approach 
  public:
    // time o(root(n) * 2 *root(n))
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
    vector<int> primeFac(int n) {
        vector<int>ans;
        if (n == 1) return ans; // edge case
        for(int i = 2 ; i * i <= n ; i++){
            if( n % i == 0 ){
                if(isPrime(i)) ans.push_back(i);
                if(n / i != i){
                    if(isPrime(n / i)) ans.push_back(n / i);
                }
            }
        }
        if (isPrime(n)) { // if n itshelf is prime
            ans.push_back(n);
        }
        return ans;
    }
};

approach 2: Optimized Approach

class Solution { // optimesd approach 
  public:
    // time o(root(n) * log n)
    vector<int> primeFac(int n) {
        vector<int>ans;
        for(int i = 2; i * i <= n ;i++){
            if( n % i == 0) ans.push_back(i);
            while(n % i == 0) n = n / i;
        }
        if (n != 1) { // if n itshelf is prime
            ans.push_back(n);
        }
        return ans;
    }
};