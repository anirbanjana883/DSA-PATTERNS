Largest number in K swaps

time complexity  O(n^k)
space complexity O(n)+O(n) recursn stack place + string copiying 
 
class Solution {
  public:
    int n;
    
    char findMax(string &s, int start) {
        return *max_element(s.begin() + start, s.end());
    }

    void solve(string& s, int k, string& res, int start) {
        if (k == 0 || start == n) return;

        char maxEl = findMax(s, start);

        for (int i = n - 1; i >= start; i--) {
            if (s[i] == maxEl && s[i] > s[start]) {
                swap(s[start], s[i]);
                if (s.compare(res) > 0) res = s;
                solve(s, k - 1, res, start + 1);
                swap(s[start], s[i]);
            }
        }

        solve(s, k, res, start + 1);
    }

    string findMaximumNum(string& s, int k) {
        n = s.size();
        string res = s;
        solve(s, k, res, 0);
        return res;
    }
};
