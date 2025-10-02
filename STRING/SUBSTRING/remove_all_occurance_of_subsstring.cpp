1910. Remove All Occurrences of a Substring

approach 1:
t.c  O(N^2)

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            // This starts an infinite while loop that will
            //  keep running until it encounters a break statement.
            while (true) {
                // The index of the first character of the found
                // substring is stored in idx. If part is not found,
                // s.find(part) will return string::npos.
                int idx = s.find(part);
    
                if (idx == string::npos)
                    break;
    
                // This line removes the substring part from s starting at the
                //     index idx and spanning the length of
                //         part.This effectively erases the first occurrence of part
                //             from s.
                s.erase(idx, part.length());
            }
            return s;
        }
    };

approach 2:

using stack 

class Solution {
    public:
        bool check(stack<char> st, string part, int n) {
            // we can not modify original string
            stack<char> temp = st;
            for (int i = n - 1; i >= 0; i--) {
                if (part[i] != temp.top())
                    return false;
                temp.pop();
            }
            return true;
        }
        string removeOccurrences(string s, string part) {
            int m = s.size();
            int n = part.size();
            stack<char> st;
    
            for (int i = 0; i < m; i++) {
                st.push(s[i]);
    
                // check is stack length is
                // same as length of part
                // check if part is present in string
                // or not
    
                if (st.size() >= n && check(st, part, n) == true) {
                    for (int j = 0; j < n; j++) {
                        st.pop();
                    }
                }
            }
    
            string result = "";
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };


approach 3: using string as stack

class Solution {
    public:
        string removeOccurrences(string s, string part) {
            string result="";
            int n=part.size();
            for(auto &ch:s){
                result.push_back(ch);
    
                if(result.length()>=n && result.substr(result.length()-n)==part){
                    result.erase(result.length()-n);
                }
            }
            return result;
        }
    };