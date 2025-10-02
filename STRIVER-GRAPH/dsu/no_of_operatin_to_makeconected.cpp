1319. Number of Operations to Make Network Connected

class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find_parent(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find_parent(parent[x]);
    }

    void unionset(int x, int y) {
        int xParent = find_parent(x);
        int yParent = find_parent(y);

        if (xParent == yParent)
            return;
        else if (parent[xParent] < parent[yParent]) {
            parent[xParent] = yParent;
        } else if (parent[xParent] > parent[yParent]) {
            parent[yParent] = xParent;
        } else {
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // if no of edges <n-1 then not possible to connect all the computers
        if (connections.size()< n - 1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        int components=n;
        // iterating on the connections vector
        for(auto &vec:connections){
            if(find_parent(vec[0])!=find_parent(vec[1])){
                unionset(vec[0],vec[1]);
                // when two element attached then components decrease by 1; 
                components--;
            }
        }
        //let at last after union 3 component remains 
        //to connect 3 components we need nin 2 edge
        return components-1;
    }
};