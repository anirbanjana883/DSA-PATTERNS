735. Asteroid Collision

class Solution {
public:
    // time o(2n + time for sorting ) if used list time for srting can be avoided
    // space o ( n)
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        // to avoid reversing the step at last we
        // can take a list 
        for(int i = 0 ; i < n ;i++){
            if( arr[i] > 0) st.push(arr[i]);
            else{
                while(!st.empty() && (st.top() > 0) && (st.top() < abs(arr[i]))){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(arr[i])) {
                    st.pop();
                }else if(st.empty() || st.top() < 0){
                    st.push(arr[i]);
                }
            }
        }
        vector<int>result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin() , result.end());
        return result;
    }
};