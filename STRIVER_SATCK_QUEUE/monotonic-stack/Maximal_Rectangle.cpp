85. Maximal Rectangle

class Solution {
public:
    time o ( n * m)
    // space o ( m for heights array)
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        int maxArea = INT_MIN;
        for(int i = 0; i < n ; i++){
            while( !st.empty() && arr[i] < arr[st.top()]){
                int element = st.top(); // this is the nest smaller elemnt
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max( maxArea , arr[element] * (nse - pse -1));
            }
            st.push(i);
        }
        // if still element left in the stack 
        // el1( with no nse and pse ) el2(with no nse but pse as el1);
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max( maxArea , arr[element] * (nse - pse -1));
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};