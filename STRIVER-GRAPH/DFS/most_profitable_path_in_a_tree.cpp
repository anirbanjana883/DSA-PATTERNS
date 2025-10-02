2467. Most Profitable Path in a Tree

in this question we need very good reaing of the problem 
we need two dfs one for alice and another for bob

alice starts from zero and bob starts from bob

class Solution {
    public:
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> bobMap; // to store time
        int aliceIncome = INT_MIN;
    
        bool dfsBob(int curr, int time, vector<bool>& visited) {
            visited[curr] = true;
            bobMap[curr] = time;
    
            // if we reached to the zero node then 
            if (curr == 0) {
                return true;
            }
    
            // explore
            for (auto ngbr : adj[curr]) {
                if (!visited[ngbr]) {
                    if (dfsBob(ngbr, time + 1, visited)) {
                        return true;
                    }
                }
            }
    
            // if we reached to wrong path explore other path 
            bobMap.erase(curr);
            return false;
        }
    
        void DFSAlice(int curr, int t, int income, vector<bool>& visited, vector<int>& amount) {
            visited[curr] = true;
    
            // if alice and bob reached the same node at different times or alice reached first
            if (bobMap.find(curr) == bobMap.end() || t < bobMap[curr]) {
                income += amount[curr];
            } else if (t == bobMap[curr]) {
                income += (amount[curr] / 2);
            }
    
            if (adj[curr].size() == 1 && curr != 0) { // leaf node
                aliceIncome = max(aliceIncome, income);
            }
    
            for (int& ngbr : adj[curr]) {
                if (!visited[ngbr]) {
                    DFSAlice(ngbr, t + 1, income, visited, amount);
                }
            }
        }
    
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            // making adjacency list
            int n = edges.size() + 1;
            for (auto& vec : edges) {
                int u = vec[0];
                int v = vec[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            // DFS on Bob for finding time to reach each node till 0
            vector<bool> visited(n, false);
            int time = 0;
            dfsBob(bob, time, visited);
    
            // Reset the visited for DFS
            visited.assign(n, false);
            int income = 0;
            DFSAlice(0, 0, income, visited, amount);
    
            return aliceIncome;
        }
    };
    