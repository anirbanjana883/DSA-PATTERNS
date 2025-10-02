29. Divide Two Integers

approach: Broute force approach 

class Solution {
public:
    // TLE o(divisor)
    int divide(int dividend, int divisor) {
        // 21 = 3 + 3 + 3 + 3 + 3 + 3 + 3
        long long cnt  = 0;
        long long  sum = 0;
        while( (sum += divisor) <= dividend){
            cnt ++;
        }
        return cnt;
    }
};

optimal approach: using bit manipulation

class Solution {
public:
    // time o(log n * log n)
    // space o(1)
    /*
        we are removing bigger -> smaller possible
        number from the divident 
        let dividend = 22 and divisor = 3
        22 = 12 + 6 + 3
        22 = 3 * 2^2 + 3 * 2^1 + 3 * 2^0
    */
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        
        bool sign = (dividend > 0) == (divisor > 0);
        
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        
        while (n >= d) {
            long long temp = d, cnt = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                cnt <<= 1;
            }
            n -= temp;
            ans += cnt;
        }
        
        if (!sign) {
            ans = -ans;
        }
        
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        
        return (int)ans;
    }
};