Smaller on Left
or Previous Smaller Element

broute force :
using ffor loop 

time complexity O(N ^ 2);
space complexity O(N)

optimal approach :
using stack

vector<int> Smallestonleft(vector<int> &arr, int n) {
    // time complexity O( 2 * N);
    // space complexity O(2 * N)

    // Complete the function
    vector<int> ans(n); 
    stack<int> st; 
    
    for(int i = 0; i < n; i++) {
        int element = arr[i];
        while(!st.empty() && st.top() >= element) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = st.top();
        } else {
            ans[i] = -1; 
        }
        st.push(element);
    }
    
    return ans;
}
