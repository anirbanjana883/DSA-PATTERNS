Detect Cycle using DSU


(*) if parent same -> cycle present
(*) else find union

 public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unionSet(int x,int y){
        int xParent=find(x);
        int yParent=find(y);
        
        if(xParent==yParent) return;
        else if(rank[xParent]<rank[yParent]){
            parent[xParent]=yParent;
            
        }else if(rank[xParent]>rank[yParent]){
            parent[yParent]=xParent;
            
        }else{
            parent[xParent]=yParent;
            rank[yParent]++;
        }
    }
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    parent.resize(V);
	    rank.resize(V);
	    for(int i=0;i<V;i++){
	        parent[i]=i;
	        rank[i]=0;
	    }
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){
                if(u<v){
                    int uParent=find(u);
                    int vParent=find(v);
                    // if same parent then cycle present
                    if(uParent==vParent) return 1;
                   // else do union
                    unionSet(u,v);
                }
            }
        }
        return 0;
	}