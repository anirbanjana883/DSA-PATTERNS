50. Pow(x, n)

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