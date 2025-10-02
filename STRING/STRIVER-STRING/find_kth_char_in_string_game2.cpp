3307. Find the K-th Character in String Game II


class Solution {
public:
    //T.C : O(log(k))
    //S.C : O(log(k))) of system stack
    typedef long long ll;
    char kthCharacter(long long k, vector<int>& operations) {
        /*
         kth element in l length string (let x) =
         (k - l/2) th char in l/2 length (let y)
         if  opr [i] == 0 then x == y
         if opr [i] == 1 then y == x + 1 next char 
        */
        
        // base case
        if ( k == 1) return 'a';

        int n = operations.size();
        ll len = 1;
        int operation = -1;
        ll new_k = -1;
        for(int i=0;i<n;i++){
            len *= 2;
            if( len >= k){
                operation = operations[i];
                new_k = k - (len/2);
                break;
            }
        }
        char ch = kthCharacter( new_k , operations);

        if ( operation == 0 ) return ch;
        return ch == 'z' ? 'a' : ch + 1;
    }
};

class Solution {
public:
    //T.C : O(log(k))
    //S.C : O(1) of system stack
    typedef long long ll;
    char kthCharacter(long long k, vector<int>& operations) {
        //  look at the constrain you 
        //  have to solve the question without producinf the string 
        // so we have to design an algo such that we can raech form kth char 
        //  just like recursn but in better way 

        // as the length is increrasing by 2 
        //  so the smlalest length that will contain k is log k = let jump 
        // then 2 ^ jump -1 will give the exact middle point 

        int count_opr = 0;
        ll val = k;
        while(val > 1){
            int jump = ceil (log2(val));
            val -= pow(2, jump-1);
            count_opr += operations[jump - 1];
        }
        return char('a'+(count_opr % 26));
    }
};