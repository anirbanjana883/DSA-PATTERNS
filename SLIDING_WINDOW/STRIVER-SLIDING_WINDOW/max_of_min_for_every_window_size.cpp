Max of min for every window size

>>> similar problem as ->> 84. Largest Rectangle in Histogram
please try to find all the subarray in pen paper you will find it

class Solution { // Horizental moving 
  public:
    // time o ( n ^ 3)
    // space o ( n )
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>ans(n , 0);
        for(int i = 0 ; i < n ; i++){
            int mx = -1e9;
            for(int j = 0 ; j < n - i ; j++){
                int mn = 1e9;
                for(int k = j ; k < j + i + 1 ; k++){
                    mn = min ( mn , arr[k]);
                }
                mx = max(mx , mn);
            }
            ans[i] = mx;
        }
        return ans;
    }
};

class Solution {
  public:
    // time o ( n ^ 2)
    // space o ( n )
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>ans( n , 0);
        for(int i = 0 ; i < n ; i++){
            int mn = arr[i];
            for(int j = i ; j < n ; j++){
                mn = min(mn , arr[j]);
                int windowSize = j - i + 1;
                ans[windowSize - 1] = max (ans[windowSize - 1] , mn);
            }
        }
        return ans;
    }
};


class Solution {
  public:
      // time o ( n )
    // space o ( n )
    vector<int>PSE(vector<int>& arr){
        int n = arr.size();
        vector<int>pse(n , -1);
        stack<int>st;
        
        for(int i = 0 ; i < n ;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>NSE(vector<int>& arr){
        int n = arr.size();
        vector<int>nse(n , n);
         stack<int>st;
        
        for(int i = n - 1 ; i >= 0 ;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>pse = PSE(arr);
        vector<int>nse = NSE(arr);
        vector<int>ans(n , -1);
        
        for(int i = 0 ; i < n ; i++){
            int windowSize = nse[i] - pse[i] - 1;
            ans[windowSize - 1] = max(ans[windowSize - 1], arr[i]);
        }
        
        // Fill remaining positions (some window sizes might not have been set)
        for(int i = n - 2; i >= 0 ; i--){
            ans[i] = max(ans[i] , ans[i + 1]);
        } 
        return ans;
    }
}; 
