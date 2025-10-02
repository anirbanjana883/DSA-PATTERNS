886. Possible Bipartition

class Solution {
public:
    bool checkBipertite(unordered_map<int,vector<int>>&adj,int currentColor,vector<int>&color,int u){
        // colored the current node 
        color[u]=currentColor;
        // explore the ather node
        for(auto &v:adj[u]){
            // if u and v have the same color 
            // means can not be pertitable 
            if(color[u]==color[v]) return false;
            // if not colored then color it 
            if(color[v]==-1){
               int  colorOfv=1-currentColor;
                if(checkBipertite(adj,colorOfv,color,v)==false) return false ;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // just check bipertite
        unordered_map<int,vector<int>>adj;
        for(auto &edge:dislikes){
            int u=edge[0]; 
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // coloure vector
        // vector<int>color(n+1,-1);  for 1 based indexing
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                // if we get false from any node 
                //means we can not bipertite
                if(checkBipertite(adj,1,color,i)==false){
                    return false;
                }
            }
        }
        return true;
    }
};