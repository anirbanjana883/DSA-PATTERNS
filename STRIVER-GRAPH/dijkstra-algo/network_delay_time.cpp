743. Network Delay Time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // making the adjecency list
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            // since it is a directed graph
            adj[u].push_back({v,w});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(n+1,INT_MAX);
        // since in the question it is given that the starting node is k
        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;

                if((dist+wt)<result[adjNode]){
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                }
            }
        }
        // if any node is unreachable 
        int mintime=INT_MIN;
        for(int i=1;i<=n;i++ ){
            mintime=max(mintime,result[i]);
        }
        return mintime==INT_MAX?-1:mintime;
    }
};