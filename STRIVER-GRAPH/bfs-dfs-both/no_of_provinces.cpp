547. Number of Provinces

simple dfs

class Solution {
public:
    void DFS(unordered_map<int,vector<int>>&adj,int u,vector<int>&visited){
        visited[u]++;

        for(auto &v:adj[u]){
            if(!visited[v]){
                 DFS(adj,v,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //  converting to adjecency list 
        int V=isConnected.size();
        unordered_map<int,vector<int>>adj;
        // 1 base indexing
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                // since this is an undirected graph
                if(isConnected[u][v]==1){
                    adj[u].push_back(v);
                     adj[v].push_back(u);
                }
            }
        }
        vector<int>visited(V,0);
        int noOfProvinces=0;
        // this loop will cover the case of disconnected nodes
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(adj,i,visited);
                noOfProvinces++;
            }
        }
        return noOfProvinces;
    }
};

simple bfs

class Solution {
public:
    // time o(v ^ 2)
    // space o(v ^ 2)
    void BFS(unordered_map<int,vector<int>>&adj,int u,vector<int>&visited){
       queue<int>q;
       q.push(u);
       visited[u]=1;

       while(!q.empty()){
        int u=q.front();
        q.pop();

        for(auto &v:adj[u]){
            if(!visited[v]){
                q.push(v);
                visited[v]=1;
            }
        }
       }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //  converting to adjecency list 
        int V=isConnected.size();
        unordered_map<int,vector<int>>adj;
        // 1 base indexing
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                // since this is an undirected graph
                if(isConnected[u][v]==1){
                    adj[u].push_back(v);
                     adj[v].push_back(u);
                }
            }
        }
        vector<int>visited(V,0);
        int noOfProvinces=0;
        // this loop will cover the case of disconnected nodes
        for(int i=0;i<V;i++){
            if(!visited[i]){
                BFS(adj,i,visited);
                noOfProvinces++;
            }
        }
        return noOfProvinces;
    }
};