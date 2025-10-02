kosarajus algorithm  ====>  can find stringly cinnected component 
step 1.topological sort and put in stack(dfs)  o(V+E)
step 2.reverse all edges O(v+E)
step 3.call dfs according to the stack order   o(V+E)

code==> time complexity O(V+E)

class Solution
{
	public:
	void dfsTravarsal(int u,vector<vector<int>>&adjReversed,vector<bool>&visited){
	    visited[u]=1;
	    
	    for(auto &v:adjReversed[u]){
	        if(!visited[v]){
	            dfsTravarsal(v,adjReversed,visited);
	        }
	    }
	}
    // putting nodes in stack in topo order 	
	void dfsFill(int u,vector<vector<int>>& adj,vector<bool>&visited,stack<int>&st){
	    visited[u]=1;
	    
	    for(auto &v:adj[u]){
	        if(!visited[v]){
	            dfsFill(v,adj,visited,st);
	        }
	    }
	   // when all chile are instack then put parent in stack
	   st.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // step 1.store topological order in stack
        stack<int>st;
        vector<bool>visited(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                // putting vectex in stack in topologically sorted order
                dfsFill(i,adj,visited,st);
            }
        }
        // step 2. reverse all teh edges
        vector<vector<int>>adjReversed(V);
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){ // this line means u---->v 
            // but we need v---->
                adjReversed[v].push_back(u);
            }
        }
        //mark all node unvisited again
        int countScc=0;
        visited=vector<bool>(V,0);
        
        while(!st.empty()){
            int node =st.top();
            st.pop();
            
            if(!visited[node]){
                dfsTravarsal(node,adjReversed,visited);
                // when 1 dfs done means we have found one scc
                countScc++;
            }
        }
        return countScc;
    }
};