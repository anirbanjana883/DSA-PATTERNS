28. Find the Index of the First Occurrence in a String

** basically it is a question of  z index algo 
but here done with kmp 

Time Complexity: O(n + m)
Space Complexity: O(m + k)

class Solution {
public:
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

    int strStr(string txt, string pat) {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        findLPS(pat, lps);

        int i = 0, j = 0;

        while(i < n) {
            if(txt[i] == pat[j]) {
                i++;
                j++;
            }

            if(j == m) {  
                return i - j;  // if 1 lenght i-j+1
            } else if(i < n && txt[i] != pat[j]) {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};