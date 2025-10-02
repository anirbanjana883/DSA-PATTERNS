84. Largest Rectangle in Histogram

approach 1 : 

class Solution {
public:
    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previousSmallerElement(heights);
        vector<int> nse = nextSmallerElement(heights);
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
};

class Solution {
public:
    // time o ( n + n(for popping element))
    // space o ( n for stack)
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
};


