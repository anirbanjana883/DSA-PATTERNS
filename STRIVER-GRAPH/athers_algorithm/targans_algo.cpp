1192. Critical Connections in a Network

An edge is called a bridge if removing it increases the number of connected components of the graph.
if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.

class Solution {
public:
    // time o( v + 2e)
    // space o( v + 2e)
    int timer = 1;

    void dfs(int node, int parent, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited, vector<int>& time, vector<int>& lowTime,
             vector<vector<int>>& bridges) {
        
        visited[node] = true;
        time[node] = lowTime[node] = timer++;
        
        for (auto& neighbor : adj[node]) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node, adj, visited, time, lowTime, bridges);
                lowTime[node] = min(lowTime[node], lowTime[neighbor]);

                if (lowTime[neighbor] > time[node]) {
                    bridges.push_back({node, neighbor});
                }
            } else {
                // back edge
                lowTime[node] = min(lowTime[node], time[neighbor]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> time(n, -1);
        vector<int> lowTime(n, -1);
        vector<vector<int>> bridges;

        // We can start from any node; assuming 0
        dfs(0, -1, adj, visited, time, lowTime, bridges);

        return bridges;
    }
};
