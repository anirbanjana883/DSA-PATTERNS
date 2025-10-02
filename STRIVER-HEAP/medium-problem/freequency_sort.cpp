1636. Sort Array by Increasing Frequency

class Solution {
public:
    // time O(n + m log m)
    // space o(n)
    typedef pair<int, int> p;
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (auto& it : nums) {
            mp[it]++;
        }
        auto comp = [](p a, p b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };

        priority_queue<p, vector<p>, decltype(comp)> pq(comp);
        for (auto& it : mp) {
            pq.push({it.second, it.first});
        }
        vector<int> result;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int freq = p.first;
            int element = p.second;

            while (freq--) {
                result.push_back(element);
            }
        }
        return result;
    }
};