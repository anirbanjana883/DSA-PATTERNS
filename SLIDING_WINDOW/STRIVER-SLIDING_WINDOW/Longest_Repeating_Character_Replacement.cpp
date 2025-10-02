424. Longest Repeating Character Replacement

extreme broute force approach ; generate all substring 

class Solution {
public:
    // time o ( n ^ 2)
    // space o ( n )
    bool check(unordered_map<char, int>& mp, int window_size, int k) {
        int max_freq = 0;
        for (auto& it : mp) {
            max_freq = max(max_freq, it.second);
        }
        return (window_size - max_freq) <= k;
    }

    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;  // Increment frequency
                if (check(mp, j - i + 1, k)) {
                    max_len = max(max_len, j - i + 1);
                } else {
                    break;  // Early exit: further expansion won't help
                }
            }
        }
        return max_len;
    }
};

optimied sliding window approach :