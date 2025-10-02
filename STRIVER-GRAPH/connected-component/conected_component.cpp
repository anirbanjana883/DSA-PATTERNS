Connected Components in an Undirected Graph

class Solution {
  public:
    // time O(V + E)
    // space O(V + E)
    vector<vector<int>> result;
    void DFS(unordered_map<int,vector<int>>&adj,vector<bool>&visited,vector<int>&temp,int u){
        visited[u] = true;
        temp.push_back(u);
        
        for(auto &v: adj[u]){
            if(!visited[v]){
                DFS(adj,visited,temp,v);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int,vector<int>>adj;
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,false);
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                vector<int>temp;
                DFS(adj,visited,temp,i);
                result.push_back(temp);
            }
        }
        return result;
    }
};
