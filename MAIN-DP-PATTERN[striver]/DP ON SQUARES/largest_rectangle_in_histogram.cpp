84. Largest Rectangle in Histogram

approach 1:

🕒 Time Complexity = O(n)
💾 Space Complexity = O(n)


class Solution {
public:
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
};


approach 2: extremelt tough to get intution 

🕒 Time Complexity = O(n)
💾 Space Complexity = O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        int maxAns=0;
        int n=arr.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || arr[st.top()]>=arr[i])){
                int height=arr[st.top()];
                st.pop();
                int width;
                if(st.empty()) width=i;
                else width=i-st.top()-1;
                maxAns=max(maxAns,width*height);
            }
            st.push(i);
        }
        return maxAns;
    }
};