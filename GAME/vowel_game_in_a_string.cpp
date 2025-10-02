3227. Vowels Game in a String

class Solution {
public: 
    bool isVowel(char ch){
        return ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u';
    }
    bool doesAliceWin(string s) {
        // bob can win only if vowel count = 0 ;
        // in  all ather case alice will win
        int cnt = 0; 
        for(auto &ch : s){
            if(isVowel(ch)) cnt ++;
        }
        return cnt == 0 ? false : true;
    }
};