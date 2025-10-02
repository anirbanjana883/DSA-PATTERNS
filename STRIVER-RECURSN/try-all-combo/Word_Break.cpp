139. Word Break

class Solution {
public:
    // Final Time Complexity: O(n^2)
    // Final Space Complexity: O(n + m * k)
    unordered_set<string>st;
    bool solve(string s, vector<string>& word,int n ,int idx,vector<int>&dp){
        if(idx == n){
            return true;
        }
        // if present in word
        if(st.find(s) != st.end()) return true;
        // not prsent 
        // so break and check 
        if(dp[idx] != -1 ) return dp[idx];
        for(int length = 1; length <= n - idx ; length++){
            string temp = s.substr(idx , length);
           if (st.find(temp) != st.end() && solve(s , word , n , idx + length , dp) == true){
                return dp[idx] = true;
           }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& word) {
        int n = s.size();
        for(auto &it : word) st.insert(it);
        vector<int>dp(n , -1);
        return solve(s , word , n , 0 , dp);
    }
};