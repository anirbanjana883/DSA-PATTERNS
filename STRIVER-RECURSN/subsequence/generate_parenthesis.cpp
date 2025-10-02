22. Generate Parentheses

broute force approach : 

class Solution {
public:
    // time (2 ^ (2 * n) ) * (2  * n)
    // space memory limit exced o(2 * n)
    bool isValidParenthesis(string &bracket){
        int openBracketCount = 0;
        for(auto &it : bracket){
            if ( it == '(' ) openBracketCount ++;
            else {
                openBracketCount--;
                // already unbalanced
                if (openBracketCount < 0) return false;
            }
        }
        return openBracketCount == 0;
    }
    void solve ( int n , string temp , vector<string>&result){
        //  base case
        if(temp.size() == 2 * n ){
            if(isValidParenthesis(temp)){
                result.push_back(temp);
            }
            return ;
        }
        //  explore 
        temp.push_back('(');
        solve(n, temp, result);
        temp.pop_back();

        temp.push_back(')');
        solve(n, temp, result);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        //  n pair - n open n closed bracket
        string temp = ""; 
        vector< string >result;
        solve(n , temp, result);
        return result;
    }
};

optimised approach :

class Solution {
public:
    // time (2 ^ (2 * n) ) 
    // space memory limit exceed o(2 * n)
    int openCount = 0;
    int closeCount = 0;
    void solve ( int n , string temp , vector<string>&result){
        // no need of isvalid fun also 
        // because all generated string will valid guarrenty 
        //  base case
        if(temp.size() == 2 * n ){
            result.push_back(temp);
            return ;
        }
        //  explore 
        if (openCount < n){ // 1st optimisation
            temp.push_back('(');
            openCount ++;
            solve(n, temp, result);
            temp.pop_back();
            openCount --;
        }
        if(closeCount < openCount){ // 2nd optimisation 
            temp.push_back(')');
            closeCount ++;
            solve(n, temp, result);
            temp.pop_back();
            closeCount --;
        }
    }
    vector<string> generateParenthesis(int n) {
        //  n pair - n open n closed bracket
        string temp = ""; 
        vector< string >result;
        solve(n , temp, result);
        return result;
    }
};