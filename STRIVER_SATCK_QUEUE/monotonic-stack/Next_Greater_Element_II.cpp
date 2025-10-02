503. Next Greater Element II

circular array 

class Solution {
public:
    // time o ( n ^ 2)
    // space o ( n )
    vector<int> nextGreaterElements(vector<int>& arr) {
        // double the array virtually 
        int n = arr.size();
        vector<int>nge(n,-1);
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j <= i + n - 1 ; j++){
                int ind = j % n;
                if( arr[ind] > arr[i]){
                    nge[i] = arr[ind];
                    break;
                }
            }
        }
        return nge;
    } 
};

optimised approach :

class Solution {
public:
    // time o (  4 * n )
    // space o ( n )
     vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st; 

        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = arr[i % n];
            // Pop elements smaller than current (they can't be NGE for others)
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            // Update nge only for the first 'n' elements
            if (i < n) {
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(curr);
        }
        return nge;
    }
};