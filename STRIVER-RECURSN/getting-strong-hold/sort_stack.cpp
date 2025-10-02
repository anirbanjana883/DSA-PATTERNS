Sort a stack

same as sort array using recursion

class Solution {
public:
    void insert_at_bottom(stack<int> &st, int item) {
        if(st.empty()) {
            st.push(item);
            return;
        }
        int val = st.top();
        st.pop();
        insert_at_bottom(st, item);
        st.push(val);
    }
    
    void reverseStack(stack<int> &st) {
        if(st.size() == 1) return;
        int item = st.top();
        st.pop();
        reverseStack(st);
        insert_at_bottom(st, item);
    }
    
    void Reverse(stack<int> &st) {
        reverseStack(st);
    }
};