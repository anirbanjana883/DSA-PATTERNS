Number Of Islands

class Solution {
  public:
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};
    
    bool isValid(int n, int m, int i, int j){
        return i >=0 && j >= 0 && i < n && j < m;
    }

    vector<int> parent;
    vector<int> rank;

    int find_parent(int X) {
        if (parent[X] == X) return X;
        return parent[X] = find_parent(parent[X]);
    }

    void unionSet(int X, int Z) {
        int xParent = find_parent(X);
        int yParent = find_parent(Z);

        if (xParent == yParent) return;

        if (rank[xParent] < rank[yParent]) {
            parent[xParent] = yParent;
        } else if (rank[xParent] > rank[yParent]) {
            parent[yParent] = xParent;
        } else {
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        parent.resize(n * m);
        rank.resize(n * m, 0);
        for (int i = 0; i < n * m; i++) parent[i] = i;

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> ans;
        int cnt = 0;

        for (auto &it : operators) {
            int row = it[0];
            int col = it[1];

            if (visited[row][col]) {
                ans.push_back(cnt);
                continue;
            }

            visited[row][col] = true;
            cnt++;

            int nodeNo = row * m + col;

            for (auto &dir : direction) {
                int adjRow = row + dir[0];
                int adjCol = col + dir[1];

                if (isValid(n, m, adjRow, adjCol) && visited[adjRow][adjCol]) {
                    int adjNodeNo = adjRow * m + adjCol;

                    if (find_parent(nodeNo) != find_parent(adjNodeNo)) {
                        unionSet(nodeNo, adjNodeNo);
                        cnt--; // as we are connecting so no of node will be reduced
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};
