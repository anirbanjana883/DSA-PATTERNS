2104. Sum of Subarray Ranges

class Solution {
public:
    // time o ( n ^ 2)
    // space o (1)
    long long subArrayRanges(vector<int>& arr) {
      int n = arr.size();
      long long sum = 0;
      for(int i = 0 ; i < n ;i++){
        long long mn = arr[i];
        long long mx = arr[i];
        for(int j = i ; j < n ; j++){
            mx = max(mx , (long long)arr[j]);
            mn = min(mn , (long long )arr[j]);

            sum += mx - mn;
        }
      }
      return sum;
    }
};

😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒😒

class Solution {
public:
    // time o ( n )
    // space o (n)
    vector<int> previousSmallerEqualElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee = previousSmallerEqualElement(arr);
        vector<int> nse = nextSmallerElement(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (arr[i] * left * right));
        }
        return total;
    }

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

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> pge = previousGreaterElement(arr);
        vector<int> nge = nextGreaterElement(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;
            total = (total + (arr[i] * left * right));
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMaxs(nums);
        long long minSum = sumSubarrayMins(nums);
        return maxSum - minSum;
    }
};