connected undirected graph

this is the code for solving the question directly from adjecency matrix

    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int v=adj.size();
        vector<int>ans;
        vector<int>visited(v,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
           //  now 'it' will travrse all theelements in adj[index] here index==node
           for(auto &it:adj[node]){
               if(!visited[it]){
                   visited[it]=1;
                   q.push(it);
               }
           }
        }
        return ans;
    }


for practice we will convert the adj matrix into unordered map(adjecency list) and then we will agin appply dfs on it

time complexity of this approach is O(V+E) and space complexity is O(V+E) as well

  void BFS(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<int>&result){
      queue<int>q;
      
      //the elemnt which is pushed on the queue means it is visited
      q.push(u);
      //mark visited
      visited[u]=1;
      result.push_back(u);
      
      while(!q.empty()){
          int u=q.front();
          q.pop();
          
          for(int &v:adj[u]){
              if(!visited[v]){
                  q.push(v);
                  visited[v]=1;
                  result.push_back(v);
              }
          }
      }
      
  }
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &mp) {
        // Code here
        int V=mp.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v=mp[u].begin();v!=mp[u].end();v++){
                adj[u].push_back(*v); here v is a pointer so dereferancing  mendatory
            }
        }
        
        vector<int>result;
        vector<bool>visited(V,0);
        BFS(adj,0,visited,result);
        return result;
    }