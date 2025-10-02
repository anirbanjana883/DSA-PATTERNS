402. Remove K Digits

class Solution {
public:
    // time o(3 * n + k)
    // space o(n)
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char>st;
        for(int i = 0 ; i < n ;i++){
            while(!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while( k > 0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string result = "";
        while(!st.empty()){
            result+= st.top();
            st.pop();
        }
        // removing leadingzero 
        while(result.size() != 0 && result.back() == '0'){
            result.pop_back();
        }
        if(result.empty()) return "0";
        reverse(result.begin() , result.end());
        return result;
    }
};