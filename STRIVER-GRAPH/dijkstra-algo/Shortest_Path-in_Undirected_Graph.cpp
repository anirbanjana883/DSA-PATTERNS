Shortest Path in Undirected Graph

have unit weight for all

class Solution {
  public:
    // time o ( v + e)
    // space o ( v + e)
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // since all the edge wt is 1 
        // so we dont need priority queue 
        int V = adj.size();
        unordered_map<int , vector<int>>mp;
        for(int u = 0 ; u < V ; u++){
            for(auto &v :adj[u]){
                mp[u].push_back(v);
                mp[v].push_back(u);
            }
        }
        queue<int>q;
        vector<int>dist(V , 1e9);
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &adjnode : adj[node]){
                if(dist[node] + 1 < dist[adjnode]){
                    dist[adjnode] = dist[node] + 1;
                    q.push(adjnode);
                }
            }
        }
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;

    }
};