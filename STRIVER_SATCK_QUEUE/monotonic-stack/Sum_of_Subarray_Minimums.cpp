907. Sum of Subarray Minimums

class Solution {
public: 
    // time o ( n ^ 2)
    // space o ( 1)
    int M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mnsm = 0;
        for(int i  = 0 ; i < n ; i ++){
            int mn = arr[i];
            for(int j = i ; j < n ;j++){
                mn = min ( mn , arr[j]);
                mnsm = ( mnsm % M + mn) % M;
            }
        }
        return mnsm;
    }
};

optimization

class Solution {
public: 
    // time o ( 5 * n)
    // space o ( 5 * n)
    int M = 1e9 + 7;
    vector<int> previousSmallerEqualElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> psee(n); 
        stack<int> st; 
        for(int i = 0; i < n; i++) {
            //                   suttle change here then pse
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> nextSmallerElemetn(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st; 
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (i < n) {
                nse[i] = st.empty() ? n : st.top();
            }
            st.push(i); // we are storing indexes
        }
        return nse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        /*
        get the intution 
            3 4 5 2 3 4
            3 4 5 | 2 | 3 4
            4 5 | 2 | 3 
              5 | 2 | 3 4
            now if you check all the combination of right and left subarray
            you will get some ans 
            i which aubarray 2 is minimum 
        */
        int n = arr.size();
        int total = 0;
        vector<int>nse = nextSmallerElemetn(arr);
        vector<int>psee = previousSmallerEqualElement(arr);

        for(int i = 0; i < n ;i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            total = (total + (right * left * 1ll * arr[i]) % M ) % M;
        }
        return total;
    }
};


sum of subarray maximums

vector<int> previousGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    vector<int> nextGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    int sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = previousGreaterElement(arr);
        vector<int> nge = nextGreaterElement(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total = (total + (arr[i] * left * right) % MOD) % MOD;
        }
        return total;
    }