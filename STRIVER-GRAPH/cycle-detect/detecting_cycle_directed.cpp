detecting cycle in **directed** graph ======>

1. using **DFS** to detect cycle in directed graph--->
logic of undirected graph will not work here
 
 logic : if we return to a node which is visited also in inrecursn then we can say there must be a cycle

  bool isCycleDFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inRecursn){
        visited[u]=true;
        inRecursn[u]=true;
        // u-->v
        for(auto &v:adj[u]){
            // if not visited then send it for dfs
            // if we get cycle from therte then return true
            if(!visited[v] && isCycleDFS(adj,v,visited,inRecursn)){
                return true;
            }
            // if visited then cheak wheather it is in inRecursn
            else if(inRecursn[v]==1){
                return true;
            }
        }
        // when one dfs done and still we dont find cycle then mark all 
        // inRecursn as false becasuse another dfs may run
        inRecursn[u]=0;
        return false;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> mp) {
        // code here
        // converting to an adjecency lis
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v:mp[u]){
                adj[u].push_back(v);
            }
        }
        vector<bool>visited(V,false);
        vector<bool>inRecursn(V,false);
        // function call
        // for loop used to covet the disconnected graph case
        for(int i=0;i<V;i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursn)){
                return true;
            }
        }
        return false;
    }
 1. using **BFS** to detect cycle in directed graph--->
 
 > we know that topologicalSort possible only when there is no cycle in the graph
 > so we will do topolocal sort using BFS and if we are able to do it then there is no cycle otherwise there is a cycle 
 
  --------------->[ kahns algorithm]<------------------- 

 class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> mp) {
        // code here
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v:mp[u]){
                adj[u].push_back(v);
            }
        }
        // calculating indegree
        vector<int>inDegree(V,0);
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                inDegree[v]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int u=q.front();
            count++;
            q.pop();
            
            for(auto v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0) q.push(v);
            }
        }
        
        //  if topological sort happends then all node will be visited 
        // but if there is a cycle then all node willl be visited 
        if(count==V) return 0;
        return 1;
    }
};


