785. Is Graph Bipartite?

add length cycle ----> Not BIPERTITE
even length cycle----->BIPERTITE
any graph which dont have cycle  -----> BIPERTITE

>>how to recognize a question of BIPERTITE graph
 when i have to devide a graph into two subset with different property
 A bipartite graph is a graph whose vertices can be divided into two disjoint and independent

** checking a graph is bipertite or not, using DFS===>

class Solution {
  public:
    bool checkBipartiteDFS(unordered_map<int,vector<int>>&adj,int u,vector<int>&color,int currentColor){
        // we do teh color of current node with current color
        color[u]=currentColor;
        // now we will go to teh node from the current node and check
        for(auto &v:adj[u]){
            // if two adjecent node has same color
            if(color[v]==color[u]) return false;
            // this node never visited so not  colored yet
            if(color[v]==-1){
                int colorOfv=1-currentColor;//since initially it was -1 so it will become 0
              if ( checkBipartiteDFS(adj,v,color,colorOfv)==false) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& mp) {
        // Code here
        //  converting to adjecency list
        unordered_map<int,vector<int>>adj;
        int V=mp.size();
        for(int u=0;u<V;u++){
            for(auto v:mp[u]){
                adj[u].push_back(v);
            }
        }
        vector<int>color(V,-1); // at first no node is colored
        // red--->1
        // green-->0
        for(int i=0;i<V;i++){
            // if node is not visited yet then call dfs
            if(color[i]==-1){
                if(checkBipartiteDFS(adj,i,color,1)==false){
                // if we get false from here then it not bipertite
                return false;
                }
            }
        }
        return true;
    }
};

** checking a graph is bipertite or not, using BFS===>

class Solution {
public:
    bool checkBipertiteBFS(vector<vector<int>>& graph,int curr,vector<int>&color,int currentColor){
        queue<int>q;
        color[curr]=currentColor;
        q.push(curr);
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(auto v:graph[u]){
                // u and v has same color
                if(color[v]==color[u]) return 0;
                // not colored yet
                else if(color[v]==-1){
                    // first change the color
                    color[v]=1-color[u]; // 1 - 0 = 0   | 1 - 1 = 0
                    q.push(v);
                }
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>color(V,-1);
        // red-->1
        // green -->0
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(checkBipertiteBFS(graph,i,color,1)==0){
                    return 0;
                }
            }
        }

        return 1;
    }
};