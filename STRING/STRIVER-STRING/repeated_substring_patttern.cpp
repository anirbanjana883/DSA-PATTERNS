459. Repeated Substring Pattern
very famous question

some important observation 
n % length == 0 then only valid 
time_apend = n/length
length !> n/2 then only valid

follow up question 
686. Repeated String Match

for any number n no of divisor = 2 * n^(1/2) 
class Solution {
public:
    // o(2*N + 2*N^(1/2))
    bool repeatedSubstringPattern(string s) { 
        int n=s.size();
        //  little optimisation start from bigger length 
        for(int length = n/2 ; length >= 1 ;length--){  // o (2 * n^(1/2)) 
            if( n % length == 0){ // valid length 
                int no_of_apend = n/length;
                string temp="";
                string new_sub_string = s.substr(0,length); // wrost o(N)
                while(no_of_apend--){ // worst o(N)
                    temp += new_sub_string;
                }
                if(s == temp) return true;
            }
        }
        return false;
    }
};

