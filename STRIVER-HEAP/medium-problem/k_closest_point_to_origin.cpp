973. K Closest Points to Origin

class Solution {
public:
    // time o(nlogk)
    // space o(k)
    typedef pair<int,pair<int,int>> p;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we will be storing the distance from origin 
        // but insted of storing root(x ^ 2 , y ^ 2)
        // we will be storing (x ^ 2 , y ^ 2)

        priority_queue<p>pq;
        vector<vector<int>>result;
        for(auto &it : points){
            int x = it[0];
            int y = it[1];
            int dist = (x * x + y * y);
            pq.push({dist , {x , y}});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            result.push_back({p.second.first,p.second.second});
        }
        return result;
    }
};