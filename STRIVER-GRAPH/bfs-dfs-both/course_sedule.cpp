207. Course Schedule  

 (a.) BFS KAHNS algo->

class Solution {
public:  
    bool if_cycle_present(unordered_map<int,vector<int>>&adj,int V,vector<int>&inDegree){
        // topological sorting kahns algo
        queue<int>q;

        for(int i=0;i<V;i++){
            if(inDegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int u=q.front();
            count++;
            q.pop();

            for(auto v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0) q.push(v);
            }
        }
        return count==V;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //  if there exits a cycle then we can never complete the couse 
        // so detect cycle code will be applied here 
        // [a1,b1]  b1--->a1;
        //  we will use kahna algo to detect cyle here 
        // CONVERTING TOMAP
        unordered_map<int,vector<int>>adj;
        vector<int>inDegree(numCourses,0);
        // see we take iterator as vector which will directly iterate through the row
        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            // b--->a
            adj[b].push_back(a);
            inDegree[a]++;
        }
        return if_cycle_present(adj,numCourses,inDegree);
    }
};

(b.) DFS

class Solution {
public:  
    bool if_cycle_present(unordered_map<int,vector<int>>&adj,int u,vector<bool>&visited,vector<bool>&inrecursn){
        visited[u]=1;
        inrecursn[u]=1;
        for( auto v:adj[u]){
            // if not visited then call dfs
            if(!visited[v] && if_cycle_present(adj,v,visited,inrecursn)){
                return 1;
            }
            else if(inrecursn[v]==1){
                return 1;
            }
        }
        inrecursn[u]=0;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //  if there exits a cycle then we can never complete the couse 
        // so detect cycle code will be applied here 
        // [a1,b1]  b1--->a1;
        // CONVERTING TO MAP
        unordered_map<int,vector<int>>adj;
       vector<bool>inrecursn(numCourses,0);
        vector<bool>visited(numCourses,0);
        // see we take iterator as vector which will directly iterate through the row
        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            // b--->a
            adj[b].push_back(a); 
        }
        for(int i=0;i<numCourses;i++){
                if(!visited[i] && if_cycle_present(adj,i,visited,inrecursn)){
                    return 0; // means you can not completee the courses have cycle;
                }
        }  
        return 1; // you can complete the course no cycle is there
    }
};

210. Course Schedule II

(a.) BFS KAHNS algo->

class Solution {
public:
    bool topo_sort(unordered_map<int,vector<int>>&adj,int numCourses,vector<int>&result,vector<int>&in_degree){
        queue<int>q;
        int count=0;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            count ++;
            q.pop();

            for(auto v:adj[u]){
                in_degree[v]--;
                if(in_degree[v]==0) q.push(v);
            }
        }
        return count==numCourses;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // the main difference from course sedule 1
        // is you have to return the topological sorted list

        // creating a graph
        unordered_map<int,vector<int>>adj;
        vector<int>in_degree(numCourses,0);
        for(auto vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
            in_degree[a]++;
        }
        // topological sorting
        vector<int>result;
        // if count = numCourses means we have done topo sort
        if(topo_sort(adj,numCourses,result,in_degree)) return result;
        // if count!=numCourses means there is a cycle means we can not sedule course
        return {};
    }
};


(b.) DFS

in this code we are using both detect cycle using dfs and 
topologicalSort using DFS

class Solution {
public:
// global veriable to cheak wheather a cycle is presnt or not
bool hasCycle=0;

    void topo_sort(unordered_map<int,vector<int>>&adj,int u,vector<int>&visited,stack<int>&st,vector<bool>&inRecursn){
       visited[u]=1;
       inRecursn[u]=1;

       for(auto &v:adj[u]){
        //  we will cheak if v is in recursn means v appearing second time in the recursn 
        // meabs there is a cycle
        if(inRecursn[v]==1){
            hasCycle=1;
        }
        if(!visited[v]){
            // first add all the child to the stack
            topo_sort(adj,v,visited,st,inRecursn);
        }
       }
    //    then put the parent into the stack
    // when recursn will ends for any node then put it into the stack 
    st.push(u);
     inRecursn[u]=0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // the main difference from course sedule 1
        // is you have to return the topological sorted list

        // creating a graph
        unordered_map<int,vector<int>>adj;
        vector<int>visited(numCourses,0);
        vector<bool>inRecursn(numCourses,0);
        for(auto vec:prerequisites){
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
        }  
        // topological sorting
        vector<int>result;
        int count =0; 
        stack<int>st;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                topo_sort(adj,i,visited,st,inRecursn);
            }
        }
        // if there is a cycle the we will return empty vector
        if(hasCycle==1){
            return {};
        }
        // bring elemnt fronm the stack
        while(!st.empty()){
            result.push_back(st.top());
            count++;
            st.pop();
        }
        // we can complete all the courses
       return result;
    }
};