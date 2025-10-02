Maximum Sum Combination

class Solution {
  public:
    // time O(n log n + m log m + k log k)
    // space o (k)
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend()); // decending sort
        // defining max heap
        // sum , {i , j}
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        
        vector<int>ans;
        pq.push({a[0] + b[0] , {0 , 0}});
        st.insert({0 , 0});
        while(ans.size() < k){
            auto p = pq.top();
            pq.pop();
            
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            
            ans.push_back(sum);
            
            if( i + 1 < n && st.find({i + 1 , j}) == st.end()){
                pq.push({a[i + 1] + b[j],{i + 1, j}});
                st.insert({i + 1, j});
            }
            if(i + 1 < n && st.find({i , j + 1}) == st.end()){
                pq.push({a[i] + b[j + 1],{i , j + 1}});
                st.insert({i , j + 1});
            }
        }
        return ans;
    }
};