50. Pow(x, n) 

what is it ??
it is one of the most efficient way to calculate 
large power (a^b) [in o(logb) time complexity ];

improvement in time complexity  o(b) ---> o(log b);

key concept : 
a^b  =  (a^(b/2))^2      when b is even 
        a*(a^(b/2))^2    when b is odd

time complexity o(log(b))
space complexity o(log(b)) auxliary stack space 

class Solution {
    public:
        double pw(double x,int n){
            // base case 
            if(n==0) return 1;
            if(n==1) return x;
            double result=(double)pw(x,n/2);
            if(n % 2==0){ // even number
                return result*result;
            }else{ // odd number
                return x * result * result;
            }
        }
        double myPow(double x, int n) {
            double ans=pw(x,n);
            if(n<0) ans=1/ans;
            return ans;
        }
    };

follow up question :
1922. Count Good Numbers