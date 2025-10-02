802. Find Eventual Safe States

DFS :

class Solution {
public:
    bool isCycleDFS(vector<vector<int>>& adj,int u,vector<bool>&visited,vector<bool>&inRecursn){
        visited[u]=1;
        inRecursn[u]=1;
        // u-->v
        for(auto &v:adj[u]){
            // if not visited then send it for dfs
            // if we get cycle from therte then return true
            if(!visited[v] && isCycleDFS(adj,v,visited,inRecursn)){
                return 1;
            }
            // if visited then cheak wheather it is in inRecursn
            else if(inRecursn[v]==1){
                return 1;
            }
        }
        // when one dfs done and still we dont find cycle then mark all 
        // inRecursn as false becasuse another dfs may run
        inRecursn[u]=0;
        return 0;
   }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // exactly same as cycle detection in dfs
        // just the nodes that are on cycle and in
        // inrecursn list them that will be answer
        int V=graph.size();
        vector<bool>visited(V,0);
        vector<bool>inRecursn(V,0);
        vector<int>safeNodes;
        // function call
        // for loop used to covet the disconnected graph case
        for(int i=0;i<V;i++){
            if(!visited[i]){
                isCycleDFS(graph,i,visited,inRecursn);
            }
        }
        for(int i=0;i<V;i++){
            // if any node is not inrecursn then it is safe 
            // because if we get a cycle then we are breking out without
            // making inrecursn false
            if(inRecursn[i]==false){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};


BFS : khans algo - > (topological sort)
since in khans algo we push the element first which have indegree 0 but
then we will not be able to continiue grpah travarsal so we have rto reverse the graph
for our convinienece

the node which will pop from queue these are safe node

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, vector<int>> adj;
        int V = graph.size();
        for (int u = 0; u < V; u++) {
            for (auto v : graph[u]) {
                adj[v].push_back(u); // reversed the graph
            }
        }
        // calculating indegree
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; u++) {
            for (auto v : adj[u]) {
                inDegree[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        vector<bool>isSafe(V , false);
        while (!q.empty()) {
            int u = q.front();
            isSafe[u] = true; // these are the nodes which are safe
            // all node which are in cycle will not be in queue
            q.pop();

            for (auto &v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0){
                    q.push(v);
                }
            }
        }

        vector<int>isSafeNode;
        for(int i = 0 ; i < V ; i++){
            if(isSafe[i] == true){
                isSafeNode.push_back(i);
            }
        }        
        return isSafeNode;
    }
};