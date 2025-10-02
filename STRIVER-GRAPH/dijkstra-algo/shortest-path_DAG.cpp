Shortest path in Directed Acyclic Graph

class Solution {
  public:
    void topoSort(int node, vector<bool>& visited, stack<int>& st, vector<pair<int, int>> adj[]) {
        visited[node] = true;
        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                topoSort(it.first, visited, st, adj);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }

        // Step 2: Topological sort
        vector<bool> visited(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                topoSort(i, visited, st, adj);
        }

        // Step 3: Initialize distances
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // source is 0

        // Step 4: Relax edges in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto &it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Step 5: Replace 1e9 (unreachable) with -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};
