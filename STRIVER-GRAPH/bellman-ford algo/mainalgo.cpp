Bellman-Ford algorithm
[follow up of dijkstra algorithm]

<> works on directed graph only
<> if the graph is not directed, we can convert it to directed graph by adding reverse edges to each edge in the graph.
<> works on undirected(with no negative weight) graph also
<> dijkstra algo can not works for negative edge weight graph, but bellman-ford can work on it.
<> bellman-ford algo can detect negative cycle in the graph, if there is a negative cycle
   in the graph, then we can not find the shortest path from source to all other vertices.

Given a weighted and directed graph of v vertices and edges, Find the **shortest distance** of all the vertex's from the source vertex, src and return a list of integers where the ith integer denotes the distance of the ith node from the source node. If a vertices can't be reach from the s then mark the distance as 10^8.
Note: If the graph contains a **negative cycle** then return an array consisting of only -1.

******since we have to do iteration on the same order so we cant not use priority quque 
as order change in the priority queue
for dijkstra algorithm time complexity is O(E+VlogV) 
code ======>  time complexity o(E*V)

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int source) {
        vector<int>result(V,1e8);
        result[source]=0;
        // according to bellman ford algorithm we can reach minimumpath 
        // by iterating just V-1 time
        // v-1 time relaxation--->
        for(int i=1;i<=V-1;i++){
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
            
                // if u is not visited then you can not go to v
                if(result[u]!=1e8 && (result[u]+w)<result[v]){
                    result[v]=result[u]+w;
                }
            }
        }
        // negative cycle detection
        // if you relax one more time then if negative cycle present then result will get updated
        // else result will not get updated
        
            for(auto &edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
            
                // if u is not visited ten you can not go to v
                if(result[u]!=1e8 && (result[u]+w)<result[v]){
                    return {-1};
                }
            }
        return result;    
    }
};