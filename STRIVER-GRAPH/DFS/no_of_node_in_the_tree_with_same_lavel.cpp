1519. Number of Nodes in the Sub-Tree With the Same Label

basically you have to return the number of node for a perticula lavel

   approach 1   https://youtu.be/4seuiuW8c0o?si=mRKV4baFtqDB1FWb

   approach 2   https://youtu.be/yZ6IM8Q-0Ac?si=__G0EYSb0sSWsUKA 

   approach 1 :

   class Solution {
public:
    // notice this function is returning vector
    vector<int> DFS(unordered_map<int,vector<int>>&adj,int u,int parent,vector<int>&result,string &labels){
        // this vector will keet count ofnlavel of each node
        vector<int>myCount(26,0);
        // finding the lavel of the current node 
        char Mylabel=labels[u];
        // increasing each nodes label 
        myCount[Mylabel-'a']+=1;       
        // after finding my count i will 
        // check if my child has same lavel or not 
        for(auto &v:adj[u]){
            // make sure that it does not return to the parnet
            if(v==parent) continue;
            
            vector<int>childCount(26,0);
            // now find label count from child]
            childCount=DFS(adj,v,u,result,labels);
            // when dfs is done then we will 
            // wpdate the labels of child to my labels count
            for(int i=0;i<26;i++){
                // adding child ciunt to my count
                myCount[i]+=childCount[i];
            }
            
        }
        result[u]=myCount[Mylabel-'a'];
        return myCount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // approach each node return a vector 
        // to its parent where the alphabet will be updated 
        // this process starts from leaf node 
        // we will do DFS but since there is no cyale so no need to
        // maintain a visited vector

        // construct the graph 
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            // since it is a undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n,0);
        //starting node  parnet
        DFS(adj, 0  ,     -1, result ,  labels);
        return result;
    }
};

approach 1 : better approach 

class Solution {
public:
    void DFS(unordered_map<int, vector<int>>& adj, int curr, int parent,
             vector<int>& result, string& labels, vector<int>& count) {
        // firts finding my labels
        char myLabels = labels[curr];
        int count_before_visiting_curr_children = count[myLabels - 'a'];
        // now my own labels count will increase by 1
        count[myLabels - 'a'] += 1;
        // now i will explore mu child
        for (auto& v : adj[curr]) {
            // if i reached to parent then return
            if (v == parent)
                continue;
            // then we will fount labels count for my children
            DFS(adj, v, curr, result, labels, count);
        }
        // now i will found labels count after visiting all the children
        int count_after_visiting_curr_children = count[myLabels - 'a'];
        result[curr] = count_after_visiting_curr_children -
                       count_before_visiting_curr_children;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges,
                              string labels) {
        // construct the graph
        unordered_map<int, vector<int>> adj;
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            // since it is a undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> result(n, 0);
        vector<int> count(26, 0); // all small letter
        DFS(adj, 0, -1, result, labels, count);
        return result;
    }
};