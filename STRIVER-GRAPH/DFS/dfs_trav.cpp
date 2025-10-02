
connected UNDIRECTED graph

this is the code for solving the question directly from adjecency matrix

  void dfs(vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans,int start){
      visited[start]=1;
      ans.push_back(start);
      for(auto it:adj[start]){
          if(! visited[it]){
            // recursn 
              dfs(adj,visited,ans,it);
          }
      }
  }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();// number of vertices
        int start=0;
        vector<int>visited(v,0);
        vector<int>ans;
        dfs(adj,visited,ans,start);
        
        return ans;
    }

    for practice we will convert the adj matrix into unordered map(adjecency list) and then we will again appply dfs on it
    
 time complexity of this approach is O(V+E) and space complexity is O(V+E) as well


    void DFS( unordered_map<int,vector<int>>&adj, int u ,vector<bool>&visited,vector<int>&result){
      if(visited[u]==true) return;
    //   if notvisited then mmaek it as visited
      visited[u]=true;
      result.push_back(u);
      for(auto &v:adj[u]){
          if(!visited[v]){
             DFS(adj,v,visited,result);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
   vector<int> dfsOfGraph(vector<vector<int>>& mp) {
        // Code here
        //creating an unordered map for practice
        int V=mp.size();
        
        // u------>v
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v=mp[u].begin();v!=mp[u].end();v++){
                adj[u].push_back(*v); here v is a pointer so dereferancing  mendatory
            }
        }
        vector<int>result;
        vector<bool>visited(V,0);
        DFS(adj,0,visited,result);
        return result;
    }