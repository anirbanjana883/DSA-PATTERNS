455. Assign Cookies

class Solution {
public:
    // time complexity: O(n log n + m log m + n + m)
    // space complexity: O(1) 
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0; // child index
        int j = 0; // cookie index
        while (i < n && j < m) {
            if (g[i] <= s[j]) { // can assign this cookie to this child
                i++; // move to the next child
            }
            j++; // move to the next cookie (regardless of assignment)
        }
        return i; // number of children assigned a cookie
    }
};