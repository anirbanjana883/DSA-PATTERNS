1584. Min Cost to Connect All Points

approach 1: using prims algorithm [time complexity= O(E+VlogV)]

class Solution {
public:
    int primsALgo(int V, unordered_map<int, vector<pair<int, int>>> adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
                           
        vector<int> visited(V, 0);
        // {weight,node}
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int dist = p.first;
            int node = p.second;

            if (visited[node])
                continue;

            visited[node] = 1;
            sum += dist;
            for (auto& v : adj[node]) {
                int adjNode = v.first;
                int adjNodeWt = v.second;

                if (!visited[adjNode]) {
                    pq.push({adjNodeWt, adjNode});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // converting to adjecency list {most important part}
        int V = points.size();
        //                        {nodes,distance}
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int x2 = points[j][0];
            int y2 = points[j][1];

            int d = abs(x1 - x2) + abs(y1 - y2);

            adj[i].push_back({j, d});
            adj[j].push_back({i, d});
        }
    }
    // as here we have to find minimum cost so
    // we can send thid adjecency list prims algo it
    // automaticlt find this ans
    return primsALgo(V, adj);
}
};


approach 2: using Kruskals algorithm [time complexity= O(ElogE) or O(ElogV)]


class Solution {
public:
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
    int kruskalALgor(int V, unordered_map<int, vector<pair<int, int>>> adj) {
        
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
                    int v = temp.first;
                    int d = temp.second;
                            //  vec[0 ,1, 2]
                    vec.push_back({u, v, d});
                    
                }
                
            }
            
            
            auto lambda = [&](auto &v1, auto &v2) {
                // sorting on the basis of weight
                return v1[2] < v2[2];
            };
            
            sort(begin(vec), end(vec), lambda);
            
            return Kruskal(vec);
            
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
            // converting to adjecency list
            int V = points.size();
            //                        {nodes,distance}
            unordered_map<int, vector<pair<int, int>>> adj;
            for (int i = 0; i < V; i++) {
                for (int j = i + 1; j < V; j++){
                    // important part
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }
        // as here we have to find minimum cost so
        // we can send thid adjecency list prims algo it
        // automaticlt find this ans
        return kruskalALgor(V, adj);
    }
};