Floyd Warshall algorithm
>>multisource shortest path algorithm
The problem is to find the shortest distances between *every pair* of vertices in a given edge-weighted directed graph. 

go to source to destination via every possible vertex and update the smallest possible node
>> also can detect negative cycle
negative cycle =negative value of sum all weight in a cycle
time complexity = O(n^3) where n is the number of vertices in the graph

code====>


class Solution {
    // in the recent change in gfg we dont need to take infinite value iit is already infinite 
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        // since -1 means there is no edge in the grid at that ce;; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1){
                    // taking thet cell value as infinite
                    mat[i][j]=1001;
                }
            }
        }
        for(int via = 0 ;via < n ;via++){ // iterating via each node
            for(int i = 0 ; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8){
                        dist[i][j] = min ( dist[i][j] , dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
        // again converting the value to -1 
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1001){
                    // taking thet cell value as infinite
                    mat[i][j]=-1;
                }
            }
        }
    }
};

how to detect negative cycle =>
        for(int i=0;i<n;i++){
            // becasue if negative it will calulating min path again again and again
            // and diagoanl element will bwcome negative
                if(mat[i][i]<0){
                   return negative cycle present;
                }
        }