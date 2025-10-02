Shortest Path in Weighted undirected graph

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // converting to adjecency list
        // we are storing {a, b, w}
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            // since it is an undirected graph
            // {node,distance}
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>result(n+1,INT_MAX);
        vector<int>parent(n+1); // to store the pnode from where it has come
        // at first each mnode is the parent of itshelf
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        // here given source is always 1
        result[1]=0;
        // {distance,npode
        pq.push({0,1});
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &it:adj[node]){
                int adjNode=it.first;
                int wt=it.second;
                 
                 if((dist+wt)<result[adjNode]){
                    //  update result
                    result[adjNode]=dist+wt;
                    pq.push({dist+wt,adjNode});
                    // updating from where we have come thst node
                    parent[adjNode]=node;
                 }
            }
        }
        // now we have to return path
        int destination=n;
        vector<int>path;
        if(result[destination]==INT_MAX) return {-1};
        //parent[node]!=node this condition willl satisdfy only for node 1
        while(parent[destination]!=destination){
            path.push_back(destination);
            destination=parent[destination];
        }
        path.push_back(1);
        path.push_back(result[n]);
        // since path is stored in reverse direction
        reverse(path.begin(),path.end());
        return path;
    }
};