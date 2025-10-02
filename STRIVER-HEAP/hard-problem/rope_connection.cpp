Minimum Cost of ropes

class Solution {
public:
    // time o(nlogn)
    // space o(n)
    int minCost(vector<int>& arr) {
        if(arr.size() == 1) return 0;

        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &it : arr) {
            pq.push(it);
        }

        int totalCost = 0;

        while(pq.size() > 1) {
            int el1 = pq.top(); pq.pop();
            int el2 = pq.top(); pq.pop();

            int sum = el1 + el2;
            totalCost += sum; // Accumulate the cost

            pq.push(sum);
        }

        return totalCost;
    }
};
