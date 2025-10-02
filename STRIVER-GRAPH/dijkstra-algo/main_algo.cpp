              
dijkstra algorithm

<>can works on both directed and undirected graph   
<>can not works on negative edge
<>can not works on graph with negative weight cycle
                >0
            1         6
        >1       3       >2
        here asjecency list will also be different

        2-----> {0,6},{1,3}
        1-----> {0,1},{2,3}
        0-----> {2,6},{1,1}  { node ,edge weight}
        let starting node 2
        node              0 1 2
        shortest distance 4 3 0

       in meanheap we will store {distance,node}
       in mean heap smallest element will be always on the top 
       priority_queue<int,vector<int>> pq; --> max heap
       priority_queue<int,vector<int>,greater<int>> pq; --> min heap

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; --> min heap

       

      <> code for dijkstra's algorithm using  priority_queue ===>

    time complexity  o(v*(log(v)+e*log(v))); or o(ev*log(v)) perticular O(E+VlogV) 

class Solution {
     public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    typedef pair<int, int> p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<p>> mp;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});  // remove if directed graph
        }

        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int dist = curr.first;
            int node = curr.second;

            for (auto &v : mp[node]) {
                int adjnode = v.first;
                int w = v.second;

                if (dist + w < result[adjnode]) {
                    result[adjnode] = dist + w;
                    pq.push({result[adjnode], adjnode});
                }
            }
        }
        return result;
    }

<>code for dijkstra's algorithm using  set ===>

using set we can avoid some extra iteration in the above code
when we get smaller distance then the distance in the result array 
then the element in the result array (not INT_MAX) no need to process further 
[see vedio of code story with mik graph concept playlist  vedio 25]
priority queue dont have to erase any element inside it but set have that functionality

set also store minimum element at the front of the set

class Solution {
  public:
    typedef pair<int, int> p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        unordered_map<int, vector<p>> mp;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});  // remove this line if graph is directed
        }

        set<p> st;
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *st.begin();
            int dist = it.first;
            int node = it.second;
            st.erase(it);
            
            for (auto &v : mp[node]) {
                int adjnode = v.first;
                int w = v.second;

                if (dist + w < result[adjnode]) {
                    // erase outdated value if already present
                    auto found = st.find({result[adjnode], adjnode});
                    if (found != st.end()) st.erase(found); // to avoid duplicate entry may be skipped
                    
                    result[adjnode] = dist + w;
                    st.insert({result[adjnode], adjnode});
                }
            }
        }
        return result;
    }
};
