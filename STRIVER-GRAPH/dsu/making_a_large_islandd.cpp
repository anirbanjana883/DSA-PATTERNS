827. Making A Large Island

class Solution {
public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<vector<int>> direction = {{0,1},{0,-1},{1,0},{-1,0}};

    int find_parent(int X) {
        if (parent[X] == X)
            return X;
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

    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        parent.resize(n * n);
        rank.resize(n * n, 0);
        for (int i = 0; i < n * n; i++) parent[i] = i;

        // Union adjacent 1s
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                int nodeNo = row * n + col;
                for (auto &dir : direction) {
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];
                    if (isValid(nrow, ncol) && grid[nrow][ncol] == 1) {
                        int adjNodeNo = nrow * n + ncol;
                        unionSet(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        // Calculate sizes of all connected components
        unordered_map<int, int> size;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    int node = row * n + col;
                    int root = find_parent(node);
                    size[root]++;
                }
            }
        }

        int maxArea = 0;
        bool hasZero = false;

        // Try flipping each 0 and calculating the area
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;

                hasZero = true;
                set<int> components;
                for (auto &dir : direction) {
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];
                    if (isValid(nrow, ncol) && grid[nrow][ncol] == 1) {
                        int adjNode = nrow * n + ncol;
                        components.insert(find_parent(adjNode));
                    }
                }

                int area = 1; // flip current 0 as 1
                for (int comp : components) {
                    area += size[comp];
                }
                maxArea = max(maxArea, area);
            }
        }

        // In case no 0s are present
        if (!hasZero) return n * n;

        // Return the maximum area found
        for (auto &p : size) {
            maxArea = max(maxArea, p.second);
        }

        return maxArea;
    }
};
