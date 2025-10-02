Kosaraju_s Algorithm

strongly connected component is only valid for directed graph..
there can be two time of question - 
    1.figure out no of scc
    2.print the scc

sort all the edges according to finishing time 
do the dfs 


class Solution {
  public:
    // time o ( v + e)
    // space o( v + e + 2v)
    void dfs(int node ,unordered_map<int,vector<int>>&adj,vector<bool>&visited,
    stack<int>&st){
        visited[node] = true;
        for(auto &v :adj[node]){
            if(!visited[v]){
                dfs(v,adj,visited,st);
            }
        }
        st.push(node);
    }

    void dfs1(int node ,unordered_map<int,vector<int>>&revAdj,vector<bool>&visited,
    stack<int>&st){
        visited[node] = true;
        for(auto &v :revAdj[node]){
            if(!visited[v]){
                dfs1(v,revAdj,visited,st);
            }
        }
        st.push(node);
    }

    int kosaraju(vector<vector<int>> &graph){
        // code here
        int n = graph.size();
        unordered_map<int,vector<int>>adj;
        for(int u = 0 ; u < n; u++){
            for(auto &v : graph[u]){
                 adj[u].push_back(v);
            }
        }

        vector<bool>visited(n , false);
        stack<int>st;

        for(int i = 0 ; i < n ;i++){
            if(!visited[i])
                dfs(i,adj,visited,st);
        }

        // noe we need to reverse the graph
        unordered_map<int,vector<int>>revAdj;
        for(int u = 0 ; u < n; u++){
            visited[u] = false; // since we want to use the visited array again
            for(auto &v : adj[u]){
                 revAdj[v].push_back(u);
            }
        }

        // the finishing time is stored in the stack
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                scc++;
                dfs1(node,revAdj,visited,st);
            }
        }
        return scc;
    }
};
