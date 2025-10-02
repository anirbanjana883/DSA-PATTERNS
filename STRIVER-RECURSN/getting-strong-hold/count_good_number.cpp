1922. Count Good Numbers

class Solution {
public:
    /*
        no of even indices = (n+1)/2
        no of odd indices = n/2
        in odd indices we can only put (2,3,5,7). given 
        and even 0 2 4 6 8 since digit can only be 0 to 9
        */
    const int M = 1e9 + 7;

    long long findPow(long long x, long long n) {
        // Base case
        if (n == 0) return 1;
        if (n == 1) return x % M;

        long long result = findPow(x, n / 2);
        result = (result * result) % M; // Modular arithmetic to prevent overflow

        if (n % 2 == 1) { // Odd number
            result = (result * x) % M;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long oddCount = findPow(5, (n + 1) / 2); // Odd positions
        long long evenCount = findPow(4, n / 2);      // Even positions

        return (oddCount * evenCount) % M;
    }
};
