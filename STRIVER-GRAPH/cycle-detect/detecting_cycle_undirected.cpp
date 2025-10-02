detecting cycle in **undirected** graph ======>

1. using **DFS** to detect cycle in undirected graph--->

approach--- if we retrun back to the parent node then it is not a cycle else it is a cycle
                the next ndoe should be visited 
                but it should not be parent node ->>cycle present

                if next node is parent then it is conferm that going on that  node we can not get cycle 
                if not parent then we have to cheak wheather visited or not if visited then it is cycle else not visited then it is not cycle

  bool isCycleDFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,int parent){
        // mark teh node visited
        visited[u]=1;
        
        for(auto &v:adj[u]){
            // cheak parent or not if parent then no need to  cheak
            if(v==parent) continue;
            
            //  if visited that means it is not parent as well as it is visited
            //   if visited and not partent taht means it is cycle 
            if(visited[v]) return 1;
            // if one cycle detected then no need to cheak other nodes
            if(isCycleDFS(adj,v,visited,u)){
                return 1;
            }
        }
        return 0;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& edges) {
        // Code here
        // cod eto convert addjecency liist
        unordered_map<int,vector<int>>adj;
        int V=mp.size();
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,0);
        // we are running  a loop to cover tthe case of disconnected 
        // graph look for example 
        for(int i=0;i<V;i++){
            if(!visited[i]  &&  isCycleDFS(adj,i,visited,-1)){
                return 1;
            }
        }
        return 0;
    }
 
t.c= O(V+E)  s.c=O(V+E)


2. using **BFS** to detect cycle in undirected graph--->

class Solution {
  public:
  
  bool isCycleBFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited){
       queue<pair<int , int>>q;
    //            node  parent
    q.push({u,-1});
    // mark visited
    visited[u]=1;
    
    // now simple bfs
    while(!q.empty()){
        pair<int ,int>p=q.front();
        q.pop();
        
        int source=p.first;
        int parent=p.second;
        
        for(auto &v:adj[source]){
            // cheak if visited or nor
            // if not visited then push it into the queue
            if(!visited[v]){
                // mark visited
                visited[v]=1;
                q.push({v,source});
            }
            // visited and not parent so there must be a cycle 
            else if(v!=parent){
                return 1;
            }
        }
    }
    return 0;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& edges) {
        // Code here
        // cod eto convert addjecency liist
        unordered_map<int,vector<int>>adj;
        int V=mp.size();
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(V,0);
        // we are running  a loop to cover tthe case of disconnected 
        // graph look for exam ple 2
        for(int i=0;i<V;i++){
            if(!visited[i]  &&  isCycleBFS(adj,i,visited)){
                return 1;
            }
        }
        return 0;
    }
};

t.c= O(V+E)  s.c=O(V+E)