1443. Minimum Time to Collect All Apples in a Tree

simeple dfs 

class Solution {
public:
    int DFS(unordered_map<int,vector<int>>&adj,vector<bool>& hasApple,int currNode,int parent){
        int time=0;
        for(auto &child:adj[currNode]){
            // if child and parent are same 
            if(child==parent){
                continue;
            }
            // we have to find child from parent
            int timeFromChild=DFS(adj,hasApple,child,currNode);
            // if we dont get any time from child 
            // if the child has apple then we need to add this branch
            // that means dont need this branch 
            if(timeFromChild>0 || hasApple[child]){
                time+=timeFromChild+2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // converting to undirected graph
        unordered_map<int,vector<int>>adj;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // simple dfs
        // as this is a tree so we should not return back to parent 
        // so we need a parent tracker
        //                 current node       parent
        return DFS(adj,hasApple,   0,          -1);
        // as there is mentioned that this is a tree(graph)
        // means there will not  be any back connection 
        // so we dont need any visited array
    }
};