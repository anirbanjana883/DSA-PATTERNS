M Coloring Problem

here converting the given graph to a adjecency list is must
class Solution {
  public:
    // time o (n ^ m);
    // space o ( 2 * n);
    vector<int>color; // to store the color
    bool isSafe(int node, unordered_map<int,vector<int>>&adj, int c) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == c) {
                return false;
            }
        }
        return true;
    }
    bool solve(int v, unordered_map<int,vector<int>>&adj, int m,int node){
        // bc
        // we are able to color all the node
        if(node == v) return true;
        
        for(int c = 1; c <= m ;c++){ //at least m colro
            if(isSafe(node,adj,c)){
                color[node] = c;
                if(solve(v,adj,m,node + 1) == true) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        color.resize(v,0);
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return solve(v,adj,m,0);
    }
};