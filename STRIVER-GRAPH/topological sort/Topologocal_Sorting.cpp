TOPOLOGICAL SORTING ==> 
*topological sorting happend only in directed graph ->
*if there is a cycle in graph then topological sorting is not possible
* there may be multiple topological possible in a directed graph

approach: we will use a stack and as node comme in DFS then we put it into the stack and then we will pop it from the stack and then we will put it into the result list
when further dfs is not poossible for any node then put it into the stack

TOPOLOGICAL SORTING [DFS]  ->

 void topologicalSort( unordered_map<int,vector<int>>&adj,int u,vector<int>&visited,stack<int>&st){
      visited[u]=1;
      for(auto &v:adj[u]){
          //   pehele bachho ko stack mein dalo then 
          if(!visited[v]){
               topologicalSort(adj,v,visited,st);
          }
      }
    // then parents ko stack mein dalo
    // when recursn ends for any node then only put it into the stack
    st.push(u);
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& mp) {
        // Your code here
        int V =mp.size();
        vector<int>result;
        vector<int>visited(V,0);
        stack<int>st;
        // converting it into adjecency lis 
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto &v:mp[u]){
                adj[u].push_back(v);
            }
        }
        for(int i=0;i<V;i++){
            if(!visited[i]){
               topologicalSort(adj,0,visited,st);
            }
        }
        // bring elemnt from stack
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }

TOPOLOGICAL SORTING [BFS] (kahns algorithm) ->

    push elemnt into the queue  only when its indegree is zero 
    during popping elemnt from queue put it into the ans
    and then decrease the indegree of all its adjacent nodes by 1

    class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& mp) {
        // Your code here
        // converting into adjecency list
        int V=mp.size();
        unordered_map<int,vector<int>>adj;
        for(int u=0;u<V;u++){
            for(auto v:mp[u]){
                adj[u].push_back(v);
            }
        }
        // calulating indegree of all theelemnts
        // 0-->1 indegree of 1 will inc.
        // 5-->4 indegree of 4 will inc.
        // step 1
        vector<int>inDegree(V,0);
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){
                inDegree[v]++;
            }
        }
        queue<int>q;
        // step 2
        // fill the queue with the elemnt which has indegree 0
        for(int i=0;i<V;i++){
            if(inDegree[i]==0) q.push(i);
        }
        // step 3
        // simple bfs
        vector<int>result;
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            q.pop();
            
            for(auto &v:adj[u]){
                // we decrease indegree of all the node to where we can go form u
                inDegree[v]--;
                //  ifn indegree becioome zero tthen push it into the queue
                if(inDegree[v]==0) {
                    q.push(v);
                }
            }
        }
        return result;
    }
};



code without making adjecency list ::

class Solution {
    private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
        vis[node]=1;
        for( auto it: adj[node]){
            if(!vis[it]) dfs(it,vis,st,adj);
        }
        st.push(node);
        
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
         int V = adj.size();  // Get the number of vertices
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

class Solution {
    public:
    //Kahn's Algorithm

    vector<int> topologicalSort(vector<vector<int>>& adj) {
           // Your code here
           
               int V = adj.size();
       vector<int> indegree(V, 0); 
       
     
       for (int u = 0; u < V; u++) {
           for (int &v : adj[u]) {
               indegree[v]++; 
           }
       }
   
       queue<int> que;
      
       for (int i = 0; i < V; i++) {
           if (indegree[i] == 0) {
               que.push(i);
           }
       }
   
       vector<int> result;
       while (!que.empty()) {
           int u = que.front();
           result.push_back(u);
           que.pop();
   
           for (int &v : adj[u]) {
               indegree[v]--;  
               
               if (indegree[v] == 0) {
                   que.push(v); 
               }
           }
       }
   
       return result;
    }
  };