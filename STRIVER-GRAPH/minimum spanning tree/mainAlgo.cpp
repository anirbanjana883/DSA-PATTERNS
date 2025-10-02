minimum spanning tree =>we should be able to pick edges with minimum weight that connect all the vertices
watch video for rivision
there will be v-1 edges if there is v number of vertices in the graph

when you are finding the minimum spanning tree of a graph, you are essentially finding the minimum cost to connect all(minimum edge weight sum)

we can find minimum spanning tree using Kruskals algorithm or Prims algorithm.

***********PRIMS ALGORITHM***************

time complexity o(E+2log(V));
push and pop() operation in priority queue take time complexity of log(V) and we are doing this operation E times so it becomes Elog(V) and we

> iff ssomeone asked us to to print the mst then we need to strore the parent 
  also in the prriority queue
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // defining minheap
        // we are using [priority queue ] because at the top therer will be only min element
        // so we can find minimum path 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // {weight,node}
        pq.push({0,0});
        vector<bool>visited(V,0);
        // caculating edge sum
        int sum=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int wt=p.first;
            int node=p.second;
            
            // if the node is already visited then no need to process it
            //  /means alray paart off mst 
            if(visited[node]) continue;
            // else mark as visited
            visited[node]=1; // added to the mst
            sum+=wt;
            for(auto &it:adj[node]){
                // the first integer denoting the endpoint of the edge and
                //the second integer denoting the weight of the edge
                int adjNode=it[0];
                int adjNode_wt=it[1];
                
                if(!visited[adjNode]){
                    pq.push({adjNode_wt,adjNode}); 
                }
            }
            
        }
        return sum;
    }
};


***********KRUSKAL ALGORITHM***************
to connect any two vertex first look at smaller edges 
1.sort the edges in ascending order
2.if any two edges is  connected then we will not take 
  if not connected then we will connect it(using dsu)

   
   class Solution{
	public:
    //DSU Code
    vector<int> parent;
    vector<int> rank;
    
    int findParent (int x) {
        if (x == parent[x]) 
            return x;
    
        return parent[x] = findParent(parent[x]);
    }
    
    void Union (int x, int y) {
        int x_parent = findParent(x);
        int y_parent = findParent(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    
    int Kruskal(vector<vector<int>> &vec) {

        int sum = 0;
        for(auto &temp : vec) {
            
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            // finding if two node have same parent or not
            int parent_u = findParent(u);
            int parent_v = findParent(v);
            
            if(parent_u != parent_v) {
                Union(u, v);
                sum += wt;
            }
            
        }

	//if(edgesConnexted != V-1) 
	    //"It's not a MST" - REMEMBER THIS ALWAYS if anyone asks you how to check if we formed an MST or not

	    
        return sum;
    }
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        parent.resize(V);
	    rank.resize(V, 0);
        // at first ecah node is a parent of itself
	    for(int i = 0; i<V; i++)
	        parent[i] = i;

        vector<vector<int>> vec;
        
        
        for(int i = 0; i<V; i++) {
            
            for(auto &temp : adj[i]) {
                // according to the question
                int u = i;
                int v = temp[0];
                int d = temp[1];
                        //  vec[0 ,1, 2]
                vec.push_back({u, v, d});
                
            }
            
        }
        
        
        auto lambda = [&](auto &v1, auto &v2) {
            // sorting on the basis of weight
            return v1[2] < v2[2];
        };
        // /sorting is the most crucaial part of kruskal algo
        sort(begin(vec), end(vec), lambda);
        
        return Kruskal(vec);
        
    }
};