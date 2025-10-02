76. Minimum Window Substring
Smallest distinct window [same question]


broute force approach : generating all the substring 

time compolexity o(n^2)
space complexity o(256)

class Solution {
    public:
        bool containsAllChars(string& str, vector<int>& freqT) {
            vector<int> freqS(128, 0);
            for (char c : str) {
                freqS[c]++;
            }
    
            for (int i = 0; i < 128; i++) {
                if (freqT[i] > 0 && freqS[i] < freqT[i]) {
                    return false;
                }
            }
    
            return true;
        }
        string minWindow(string s, string t) {
            int n = s.size();
            int m = t.size();
            
            if (n < m || m == 0) return "";
    
            // Frequency map for 't'
            vector<int> freqT(128, 0);
            for (char c : t) {
                freqT[c]++;
            }
    
            int minLen = INT_MAX;
            int startIdx = 0;
    
            // Check all possible substrings
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    // Current substring: s[i..j]
                    string curr = s.substr(i, j - i + 1);
                    
                    // Check if 'curr' contains all chars of 't'
                    if (containsAllChars(curr, freqT)) {
                        if (curr.size() < minLen) {
                            minLen = curr.size();
                            startIdx = i;
                        }
                        break; // No need to check longer substrings starting at 'i'
                    }
                }
            }
    
            return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
        }
    };

optimised approach : o(n+m)
space complexity :o(128)

class Solution {
    public:
        string minWindow(string s, string t) {
            vector<int> freqT(128, 0); // Frequency map for t
            for (char c : t) {
                freqT[c]++;
            }
    
            int left = 0, right = 0;
            int minLen = INT_MAX;
            int minStart = 0;
            int required = t.size(); // Number of characters to match
            int matched = 0;
    
            while (right < s.size()) {
                char c = s[right];
                if (freqT[c] > 0) {
                    matched++;
                }
                freqT[c]--; // Decrease frequency (can go negative for extra characters)
    
                // When all characters are matched, try to shrink the window
                while (matched == required) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        minStart = left;
                    }
    
                    char leftChar = s[left];
                    freqT[leftChar]++; // Increase frequency as we're leaving the character
                    if (freqT[leftChar] > 0) {
                        matched--; // If frequency becomes positive, we lost a match
                    }
                    left++;
                }
    
                right++;
            }
    
            return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
        }
    };

optimised approach using map 

class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char,int>freqT; // Frequency map for t
            for (char c : t) {
                freqT[c]++;
            }
    
            int left = 0, right = 0;
            int minLen = INT_MAX;
            int minStart = 0;
            int required = t.size(); // Number of characters to match
            int matched = 0;
    
            while (right < s.size()) {
                char c = s[right];
                if (freqT[c] > 0) {
                    matched++;
                }
                freqT[c]--; // Decrease frequency (can go negative for extra characters)
    
                // When all characters are matched, try to shrink the window
                while (matched == required) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        minStart = left;
                    }
    
                    char leftChar = s[left];
                    freqT[leftChar]++; // Increase frequency as we're leaving the character
                    if (freqT[leftChar] > 0) {
                        matched--; // If frequency becomes positive, we lost a match
                    }
                    left++;
                }
    
                right++;
            }
    
            return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
        }
    };