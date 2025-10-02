8. String to Integer (atoi)

class Solution {
public:
    // t o(N)
    // s o(1)
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check for empty string after trimming
        if (i == n) return 0;

        // 3. Check for sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 4. Convert digits to number
        long ans = 0;
        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (sign == 1 && ans > INT_MAX) return INT_MAX;
            if (sign == -1 && -ans < INT_MIN) return INT_MIN;

            i++;
        }

        return sign * ans;
    }
};
