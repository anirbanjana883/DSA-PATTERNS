Generate all binary strings

class Solution {
public:
    // time O(2^n), space O(n)
    vector<string> result;
    void solve(int num, string &temp, int idx) {
        // base case
        if (idx == num) {
            result.push_back(temp);
            return;
        }
        
        // Always can take 0
        temp.push_back('0');
        solve(num, temp, idx + 1);
        temp.pop_back();
        
        // Can take 1 only if last character is not 1 or string is empty
        if (temp.empty() || temp.back() != '1') {
            temp.push_back('1');
            solve(num, temp, idx + 1);
            temp.pop_back();
        }
    }
    
    vector<string> generateBinaryStrings(int num) {
        string temp = "";
        solve(num, temp, 0);
        return result;
    }
};