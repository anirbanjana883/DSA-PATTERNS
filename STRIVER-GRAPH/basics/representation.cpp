VECTOR-LIST REPRESENtation

for undirected graph  space complexity o(2E)
 
#include<bits/stdc++.h>
using namespace std;
int main(){
  vector<int>adj[n+1];
  int n;  number of nodes
  int m;  number of edges  
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  return 0;
}

for directed graph space complexity o(E)
 
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>adj[n+1];
  int n;  number of nodes
  int m;  number of edges      
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;
   // u------>v
    adj[u].push_back(v);
    
  }
  return 0;
}

another methode of creation of adjecency vector of vector

for adjecency matrix of undirected graph space complexity o(n^2)
for adjecency list of undirected graph space complexity o(vertices + edges)

visualisation  
adj[0]->{1,2}
adj[1]->{2,3}
adj[2]->{}
adj[3]->{}

 unordered_map<int , vector<int>> adj;  spcae complexity o(vertices+edges)
 u----->v
 for(int u=0;u<V;u++){  - >where v is the number of vertices
       for(auto v=adj[u].begin();v!=adj[u].end();v++){
            adj[u].push_back(*v)   u----->v
       }
 }

  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // forming a graph
        unordered_map<int,vector<int>>adj;
        for(vectoe<int>&vec:prerequisites){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
        }
    }

how to store an weightted graph in adjecency list
 in pair 
 
node -> {weight , node}