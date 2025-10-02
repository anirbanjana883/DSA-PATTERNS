17. Letter Combinations of a Phone Number

class Solution {
    public:
        vector<string> result;
        void solve(string digits, int idx, unordered_map<char, string>& mp,
                   string& temp) {
            // idx is iterating on the digits   "23"
            if (idx >= digits.length()) {
                result.push_back(temp);
                return;
            }
            char ch = digits[idx];
            string str = mp[digits[idx]];
            // i is iterating on the string inside the digit
            for (int i = 0; i < str.length(); i++) {
                temp.push_back(str[i]);
                solve(digits, idx + 1, mp, temp);
                temp.pop_back();
            }
        }
        vector<string> letterCombinations(string digits) {
            // why backtracking...........
            // return all possible letter combinations
            // first we have to store all the char corresponding to the number
    
            if (digits.length() == 0)
                return {};
            // storing in map
    
            unordered_map<char, string> mp;
            mp['2'] = "abc";
            mp['3'] = "def";
            mp['4'] = "ghi";
            mp['5'] = "jkl";
            mp['6'] = "mno";
            mp['7'] = "pqrs";
            mp['8'] = "tuv";
            mp['9'] = "wxyz";
    
            string temp = "";
            solve(digits, 0, mp, temp);
            return result;
        }
    };