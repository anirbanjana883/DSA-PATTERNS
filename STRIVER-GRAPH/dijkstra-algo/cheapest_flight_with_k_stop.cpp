787. Cheapest Flights Within K Stops

class Solution {
public:
    // time o ( k * e )
    // space o( n + e )
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &ft : flights){
            int u = ft[0];
            int v = ft[1];
            int cost = ft[2];
            adj[u].push_back({v , cost});
        }
        vector<int>dist(n , 1e9);
        queue<pair<int, int>>q;
        q.push({src,0});
        dist[src] = 0;

        int step = 0;
        while( !q.empty() && step <= k){
            int N = q.size();
            while(N--){
                int currNode = q.front().first;
                int currPrice = q.front().second;
                q.pop();
                for(auto &v : adj[currNode]){
                    int node = v.first;
                    int price = v.second;

                    if(currPrice + price < dist[node]){
                        dist[node] = currPrice + price;
                        q.push({node, currPrice + price});
                    }
                }
            }
            step ++;
        }        
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};