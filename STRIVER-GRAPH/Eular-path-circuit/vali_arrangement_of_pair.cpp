2097. Valid Arrangement of Pairs

HIERHOLZERS ALGOTITHM  ===>

Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]] only this can be  the eular path

        11------->9----->4------>5---->1


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // here in question it was given that eular path must be present
        // Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
        // means  [[5-->1],[4-->5],[11-->9],[9-->4]]
        // step 1 find indegree and out degree 
        // step 2 from there find source node 
        // building adjecency node 
        unordered_map<int,vector<int>>adj;
        // building indegree outdegree vector
        unordered_map<int,int>in_degree,out_degree;
        //               { node,in/out degree}
        // key = node, value=in/out degree
        for(auto &edge:pairs){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);//u---->v
            out_degree[u]++;
            in_degree[v]++;
        }
        // finding the source node 
        int sourceNode=pairs[0][0];
        for(auto &it:adj){
            int node =it.first;
            if(out_degree[node]-in_degree[node]==1){
                sourceNode=node;
                break;
            }
        }
        // do DFS
        vector<int>eularianPath;// to store eular path
        stack<int>st;// to do dfs

        st.push(sourceNode);
        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int neighbour=adj[curr].back();
                adj[curr].pop_back();
                st.push(neighbour); 

            }else{
                eularianPath.push_back(curr);
                st.pop();
            }
        }        
        // result building 
        reverse(eularianPath.begin(),eularianPath.end());
        vector<vector<int>>result;
        for(int i=0;i<eularianPath.size()-1;i++){//since we are pushing i and i+1
        // so loop notice condition
            result.push_back({eularianPath[i],eularianPath[i+1]});
        }
        return result;
    }
};