Euler circuit and Path

class Solution {
public:
    void DFS(vector<int>adj[],int u,vector<bool>&visited){
        visited[u]=1;
        for(auto v:adj[u]){
            if(!visited[v]){
                 DFS(adj,v,visited);
            }
        }
    }
    bool isConnected(int V,vector<int>adj[]){
        // pick any non zero vertex and do dfs 
        int nonZeroVertex=-1; // we dont know any non zero vertex
        for(int i=0;i<V;i++){
            if(adj[i].size()!=0){
                nonZeroVertex=i;
                break;
            }
        }
        // now we know that if we do dfs from i
        // then all node should be covered if all are connected
        vector<bool>visited(V,0);
        DFS(adj,nonZeroVertex,visited);
        
        // cheak if all non zero degree vertex are visited or not
        for(int i=0;i<V;i++){
            // not visited       non zero degree
            if(visited[i]==0 && adj[i].size()!=0) return 0;
        }
        return 1;
    }
	int isEulerCircuit(int V,vector<int>adj[]){

	   // steps to cheak an eular circuit
	   //step 1 cheak if allnon zero degree vertex are connected
	   if(isConnected(V,adj)==0){ //sometime tis is not require you will given all connected
	       return 0;// non eularian
	   }
	   //step 2 if odd degree > 2 non eularian
	   //       if odd degree == 2  eular path
	   //       if odd degree ==0 eular circuit
	   int addDegreeVertices=0;
	   for(int i=0;i<V;i++){
	       if(adj[i].size()%2!=0){ // add degree vertices
	           addDegreeVertices++;
	       }
	   }
	   //if odd degree > 2 non eularian
	   if(addDegreeVertices>2) return 0;
	   // if odd degree == 2  eular path
	   else if(addDegreeVertices==2) return 1;
	   //if odd degree ==0 eular circuit
	   else if(addDegreeVertices==0) return 2;
	}
};
