797. All Paths From Source to Target

class Solution {
public://need backtracking
    void DFS(vector<vector<int>>& graph,int source,int target,vector<vector<int>>&result,vector<int>&temp){
        temp.push_back(source);
        if(source==target) {
            // means we have reach our path
            result.push_back(temp);
        }else{
            // explore ather path 
            for(auto &v:graph[source]){
                DFS(graph,v,target,result,temp);
            }
        }
        // when one path explored then back track it 
        temp.pop_back();
   }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        vector<int>temp;
        int n=graph.size();
        int source=0;
        int target=n-1;
        DFS(graph,source,target,result,temp);
        return result;
    }
};