 void matrix_to_adjecencylist(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> adjlist[v];
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
 }  this will convert the 2d adjecency matrix to a adjecency list

 efficient way->
 
  unordered_map<int,vector<int>>adjlist;
        for(int u=0;u<V;u++){
            for(auto v:adj[u]){
                adj[u].push_back(v);
            }
        }