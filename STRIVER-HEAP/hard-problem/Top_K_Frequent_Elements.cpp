347. Top K Frequent Elements

broute force approach :

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto &it:mp){
            int num = it.first;
            int frq = it.second;
            pq.push({frq,num});
        }
        vector<int>result;
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

optimal approach :


class Solution {
public:
    // time complexity o(n)
    // space complexity o(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        vector<vector<int>> bucket(n + 1);
        //  bucket [i] = element having i freequency 
        // index = freq
        // value = element 
        // intution elemnt can have max freq at most n
        for(auto &it:mp){
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }
        // make result;
        vector<int>result;
        for(int i = n ; i >= 0; i--){
            if(bucket[i].size() == 0) continue;

            while(bucket[i].size() > 0 && k > 0){
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};