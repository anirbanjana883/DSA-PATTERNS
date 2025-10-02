841. Keys and Rooms


class Solution {  //DFS
public:
    void DFS(vector<vector<int>>& rooms,int u,vector<bool>&visited){
        visited[u]=true;
        for(auto &v:rooms[u]){
            if(!visited[v]){
                DFS(rooms,v,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // basically you are given an adgecency list
        // approach you will travarse all the node if any node become untravarsed
        // we can not open all the node 
        int n=rooms.size();
        vector<bool>visited(n,false);
        DFS(rooms,0,visited);
        for(auto it:visited){
            if(it==false) return false;
        }
        return true;
    }
};

can also be so;ved using BFS ............