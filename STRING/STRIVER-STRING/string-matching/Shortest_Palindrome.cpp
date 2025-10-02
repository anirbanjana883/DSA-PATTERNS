214. Shortest Palindrome

class Solution {
public:
    // time o(n)
    // space o(n)
    void findLPS(string& pat, vector<int>& lps) {
        int m = pat.size();
        int length = 0;
        int i = 1;
        while(i < m) {
            if(pat[i] == pat[length]) {
                length++;
                lps[i] = length;  
                i++;
            } else {
                if(length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        /*
         how to think this is a problem of KMP 
         lps[i] - from 0 to i, the longest prefix and suffix which are equal 
         here longest prefix in s which is equal to rev
        */
        string rev = s;
        int n = s.size();
        reverse(rev.begin(),rev.end());
        string temp = s + "#" + rev;
        int ln = temp.size();
        vector<int>lps(ln , 0);
        findLPS(temp,lps);
        int length_of_str_creating_problem = lps[ln - 1];
        
        string to_append = rev.substr( 0 , n - length_of_str_creating_problem); 
        return to_append + s; 
    }
};