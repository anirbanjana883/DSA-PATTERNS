85. Maximal Rectangle

🕒 Time Complexity = O(n*m)
💾 Space Complexity = O(n)

class Solution {
public:
    // find largest area in histogram question
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int>st; // storing index
        vector<int>leftSmall(n),rightSmall(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }
        //  making the stack empty to use it again
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()) rightSmall[i]=n-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }
        int maxAns=0;
        for(int i=0;i<n;i++){
            maxAns=max(maxAns,arr[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxAns;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxAns=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
           maxAns=max(maxAns,largestRectangleArea(height));
        }
        return maxAns;
    }
};