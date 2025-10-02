1971. Find if Path Exists in Graph 

You want to determine if there is a valid path that exists from  source to  destination.


solution using DFS=>

class Solution {
public: // DFS
    bool check(unordered_map<int,vector<int>>&adj,int source, int destination,vector<bool>&visited){
        // start from source
        // if source and destination found 
        if(source==destination) return true;
        // check if the node is visited or not
        if(visited[source]==true) return false;
        // if not visited then mark visited
        visited[source]=true;
        // explore
        for(auto &v:adj[source]){
            if(check(adj,v,destination,visited)==true) return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // creating an adjecency list
        int V=edges.size();
        unordered_map<int,vector<int>>adj;
        for(vector<int>temp:edges){
            int u=temp[0];
            int v=temp[1];
            // undurected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        // we will be doing dfs and then if 
        // we can not found source and destination in same dfs 
        // that means there is no source between them
        return check(adj,source,destination,visited);
    }
};


solution using BFS=>

class Solution {
public: // BFS
    bool check(unordered_map<int, vector<int>>& adj, int source,
               int destination, vector<bool>& visited) {
        // start from source
        queue<int> q;
        // if not visited then mark visited
        q.push(source);
        visited[source] = true;
        // explore
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == destination)
                return true;
            // explore
            for (auto& v : adj[u]) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        // creating an adjecency list
        int V = edges.size();
        unordered_map<int, vector<int>> adj;
        for (vector<int> temp : edges) {
            int u = temp[0];
            int v = temp[1];
            // undurected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        // we will be doing dfs and then if
        // we can not found source and destination in same dfs
        // that means there is no source between them
        return check(adj, source, destination, visited);
    }
};


solution using DSI=>


class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }
    void makeSameGroup(int x,int y){
        int xParent=findParent(x);
        int yParent=findParent(y);

        if(xParent==yParent) return ;
        if(rank[xParent]>rank[yParent]){

            parent[yParent]=xParent;

        }else if(rank[xParent]<rank[yParent]){

            parent[xParent]=yParent;

        }else{
            parent[xParent]=yParent;
            rank[yParent]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            //each node isn parent of itshelf
            parent[i]=i;
        }
        for(auto &e:edges){
            // it will put u and v in same set
            makeSameGroup(e[0],e[1]);
        }
        // checking if bot have same parent
        return findParent(source)==findParent(destination);
    }
};