678. Valid Parenthesis String

recursn 

class Solution {
public:
    // time 3 ^ n
    // space n 
    bool solve(string &s ,int idx, int cnt){
        if(cnt < 0) return false;
        if(idx == s.size()) {
            return cnt == 0;
        }

        // opening
        if(s[idx] == '(') return solve(s,idx + 1, cnt + 1);
        // closing
        if(s[idx] == ')') return solve(s,idx + 1, cnt - 1);
        // *
        else { // '*'
            bool asOpen = solve(s, idx + 1, cnt + 1);
            bool asClose = solve(s, idx + 1, cnt - 1);
            bool asEmpty = solve(s, idx + 1, cnt);
            return asOpen || asClose || asEmpty;
        }
        return false;
    } 
    bool checkValidString(string s) {
        if(s.size() == 1) {
            if(s[0] == '*') return true;
            return false;
        }
        // think of an edge cas e
        // ( ) ) ) ( for this case cnt wil become 0 at last butnot valid 
        // anytime get cnt = -1 return false;
        return solve(s,0,0);
    }
};

memoization 

class Solution {
public:
    // time  n * n
    // space n * n
    bool solve(string &s, int idx, int cnt, vector<vector<int>>& memo) {
        if (cnt < 0) return false;
        if (idx == s.size()) return cnt == 0;
        
        if (memo[idx][cnt] != -1) return memo[idx][cnt];
        
        if (s[idx] == '(') {
            return memo[idx][cnt] = solve(s, idx + 1, cnt + 1, memo);
        } else if (s[idx] == ')') {
            return memo[idx][cnt] = solve(s, idx + 1, cnt - 1, memo);
        } else { // '*'
            bool asOpen = solve(s, idx + 1, cnt + 1, memo);
            bool asClose = solve(s, idx + 1, cnt - 1, memo);
            bool asEmpty = solve(s, idx + 1, cnt, memo);
            return memo[idx][cnt] = asOpen || asClose || asEmpty;
        }
    }
    
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1)); // cnt can go up to n
        return solve(s, 0, 0, memo);
    }
};

greedy aspproach 

class Solution {
public:
    // time o(n)
    // space o(1)
    bool checkValidString(string s) {
        // we will be maintaing a range of answer 
        int mn = 0;
        int mx = 0;

        int n = s.size();
        for(int i = 0; i < n ;i++){
            if( s[i] == '('){
                mn ++;
                mx ++;
            }else if( s[i] == ')'){
                mn --;
                mx --;
            }else{
                mn = mn - 1;
                mx = mx + 1;
            }
            if( mn < 0) mn = 0;
            if( mx < 0) return false; // not possible
        }
        return mn == 0;
    }
};