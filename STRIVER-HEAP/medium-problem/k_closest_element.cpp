658. Find K Closest Elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        auto comp = [x](int a, int b) {
            if (abs(a - x) == abs(b - x))
                return a < b;
            return abs(a - x) < abs(b - x);
        };

        sort(arr.begin(), arr.end(), comp); // o (nlogn)
        vector<int> result(arr.begin(), arr.begin() + k);// o(k)
        sort(result.begin(), result.end()); // 0(klogk)
        return result;
    }
};

class Solution {
public:
    //  O(n log k + k log k) time 
    // o(k) space 
    typedef pair<int,int>p;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int>result;
        // max-heap based on absolute difference, break tie by larger value
        auto comp = [](p a, p b) {
            if (abs(a.first) == abs(b.first))
                return a.second < b.second;  // prefer larger to pop first
            return abs(a.first) < abs(b.first);
        };

        priority_queue<p, vector<p>, decltype(comp)> pq(comp);
        for(int i = 0; i < n ;i++){
            pq.push({arr[i] - x , arr[i]});
            while(pq.size() > k){
                pq.pop();
            } 
        }
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin() , result.end());
        return result;
    }
};

class Solution {
public:
    //  Time Complexity: O(log(n - k) + k)
//  Space Complexity: O(1) (excluding output)
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - k;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // Compare distances of arr[mid] and arr[mid + k] to x
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;  // move right
            } else {
                right = mid;     // move left
            }
        }

        // Subarray starting at left is the answer
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
