399. Evaluate Division 

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

graph 

a->{b,2.0}
b->{a,1/2.0}
b->{c,3.0}
c->{b,1/3.0}

time complexity=O(N*(V+E))

class Solution {
public:
    void DFS(unordered_map<string, vector<pair<string, double>>> &adj,string source,string destination,
    unordered_set<string> &visited,double product ,double & ans){
        // if we return back to source 
        if(visited.find(source)!=visited.end()){ 
            return;
        }
        // if not visited mark as visited
        visited.insert(source);
        // if we reached to destination 
        if(source==destination){
            ans=product;
            return;
        }
        // dfs
        for(auto &p:adj[source]){
            string v=p.first;
            double val=p.second;
            DFS(adj, v, destination, visited, product*val, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        // few things to remember
        // equations[i] = [Ai, Bi]   Ai / Bi = values[i]
        // queries[j] = [Cj, Dj]  Cj / Dj = ?
        // queries[j] = [sourece , destination ]
        int n = equations.size();
        // creating adjecency list
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < n; i++) {
            string u = equations[i][0]; // a
            string v = equations[i][1]; // b
            double val = values[i];
            adj[u].push_back({v, val});       // a/b
            adj[v].push_back({u, 1.0 / val}); // b/a
        }
        // so we will start from source and when we reaach
        // to destination  we will return result
        vector<double> result;
        for (auto& query : queries) {
            string source = query[0];
            string destination = query[1];

            double ans = -1.0;
            double product = 1.0;

            // cheaking if both souce and destination noth present in the map
            if (adj.find(source) != adj.end() &&
                adj.find(destination) != adj.end()) {
                    // to process each quary we need fresh
                    // visited set
                unordered_set<string> visited;
                DFS(adj, source, destination, visited, product, ans);
            }
            result.push_back(ans);
        }
        return result;
    }
};



same question 3387. Maximize Amount After Two Days of Conversions