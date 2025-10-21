3703. Remove K-Balanced Substrings


    // string compression approach
    /* 
        "(()(" => {( , 2},{) , 1},{( , 1} compression
        stack -> ) , 10  let cnt1
                 ( , 5   let cnt2  then pop [min(cnt1,cnt2)/k]
    */
    /* algo 
    1.compress the values of ip string 
    2.create a stack of pair
    3.add each compress value to the atsck one by one
     3.1 compare the top 2 element 
        if same then combine the value 
        else if diff and opening followed by closing then check how many k can bw removed
        if any one become zero then dont add it
        if closing followed by opening dont do anything 
    4 decompres the elm in ans string in reverse return ans
    */

class Solution {
public:
    string removeSubstring(string s, int k) {
        stack<pair<char,int>> st;

        for(char next: s) {
            // add
            if(st.empty() || next != st.top().first) {
                st.push({next, 1});
            } else {
                auto [c, cnt] = st.top(); st.pop();
                st.push({c, cnt+1});
            }
            /* what is hapening here
                "((()))()()()" cnt = {3 , 3 , 1 , 1 , 1 , 1 , 1 , 1} 
            */
            // merge
            if(st.size()>1) {
                auto [b, bcnt] = st.top(); st.pop();
                auto [a, acnt] = st.top(); st.pop();
                if(a=='(' && b==')' && acnt >= k && bcnt >= k) {
                    acnt -= k;
                    bcnt -= k;
                }
                if(acnt>0)
                    st.push({a, acnt});
                if(bcnt>0)
                    st.push({b, bcnt});
            }
        }

        string ans;
        while(!st.empty()) {
            auto [c, cnt] = st.top(); st.pop();
            ans += string(cnt, c);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};