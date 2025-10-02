5. Longest Palindromic Substring

approash: Brute Force

class Solution {
public:
    // t o( n ^ 3)
    // s o( 1 )
    bool checkPalindrome( string &s , int i ,int j){
        while(i<=j){
            if ( s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int ln = 0;
        string res="";
        for(int i = 0;i < n;i++){
            for(int j = i; j < n ;j++){
                if(checkPalindrome(s,i,j)){
                    if(ln < j- i +1){
                        ln = j- i +1;
                        res = s.substr(i, ln);
                    }
                }
            }
        }
        
        return res;
    }
};

approash 2 : done in dp section revise it also 