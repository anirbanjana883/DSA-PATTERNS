Articulation Point - I

class Solution {
  public:
    int timer = 0;

    void dfs(int node, int parent, vector<bool>& visited,
             vector<int>& timeIn, vector<int>& lowTime,
             vector<int>& mark, vector<int> adj[]) {

        visited[node] = true;
        timeIn[node] = lowTime[node] = timer++;
        int children = 0;

        for (auto& it : adj[node]) {
            if (it == parent) continue;

            if (!visited[it]) {
                dfs(it, node, visited, timeIn, lowTime, mark, adj);
                lowTime[node] = min(lowTime[node], lowTime[it]);

                if (lowTime[it] >= timeIn[node] && parent != -1) {
                    mark[node] = 1;
                }
                children++;
            } else {
                lowTime[node] = min(lowTime[node], timeIn[it]);
            }
        }

        // special case for root node
        if (parent == -1 && children > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int n, vector<int> adj[]) {
        vector<bool> visited(n, false);
        vector<int> timeIn(n);
        vector<int> lowTime(n);
        vector<int> mark(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, timeIn, lowTime, mark, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i]) {
                ans.push_back(i);
            }
        }

        if (ans.empty()) return {-1};
        return ans;
    }
};
