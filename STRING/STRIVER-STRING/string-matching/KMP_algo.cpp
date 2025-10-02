Search Pattern (KMP-Algorithm) [HARD]

the first thing that we have to understand is that 
meaning of  LPS[i] - from 0 to i, the longest prefix and suffix which are equal 

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

    vector<int> search(string& pat, string& txt) {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        findLPS(pat, lps);

        vector<int> result;
        int i = 0, j = 0;

        while(i < n) {
            if(txt[i] == pat[j]) {
                i++;
                j++;
            }

            if(j == m) {  
                result.push_back(i - j);  // if 1 lenght i-j+1
                j = lps[j - 1];
            } else if(i < n && txt[i] != pat[j]) {
                if(j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return result;
    }
};
