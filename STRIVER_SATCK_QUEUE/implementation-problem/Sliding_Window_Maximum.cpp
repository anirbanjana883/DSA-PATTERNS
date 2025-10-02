239. Sliding Window Maximum

class Solution {
public:
    // time o ( n * k)
    // space o ( n )
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>result;
        for(int i = 0 ; i <= n - k ; i++){
            int maxi = arr[i];
            for(int j = i ; j <= i + k - 1 ; j++){
                maxi = max ( maxi , arr[j]);
            }
            result.push_back(maxi);
        }
        return result;
    }
};

class Solution {
public:
    // time o ( 2n)
    // space o ( n + ( n - k))
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0 || k == 0) return {}; // Edge case
        vector<int> result;
        deque<int> dq; // Correct spelling: deque (not dequeue)

        for (int i = 0; i < n; i++) {
            // Remove elements outside the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // Maintain monotonic decreasing order
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i); // Push current index
            // Start storing results once the first window is complete
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]); // Max is at front
            }
        }
        return result;
    }
};