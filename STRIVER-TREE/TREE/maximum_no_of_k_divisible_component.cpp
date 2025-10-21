2872. Maximum Number of K-Divisible Components  [hard]

approach 1:  DFS 

Time complexity: O(n+m)
Space complexity: O(n+m)

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                                vector<int> &values, int k) {
        // Step 1: Create adjacency list from edges
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        // Step 2: Initialize component count
        int componentCount = 0;

        // Step 3: Start DFS traversal from node 0
        dfs(0, -1, adjList, values, k, componentCount);

        // Step 4: Return the total number of components
        return componentCount;
    }

private:
    int dfs(int currentNode, int parentNode, vector<int> adjList[],
            vector<int> &nodeValues, int k, int &componentCount) {
        // Step 1: Initialize sum for the current subtree
        int sum = 0;

        // Step 2: Traverse all neighbors
        for (auto neighborNode : adjList[currentNode]) {
            if (neighborNode != parentNode) {
                // Recursive call to process the subtree rooted at the neighbor
                sum += dfs(neighborNode, currentNode, adjList, nodeValues, k,
                           componentCount);
                sum %= k;  // Ensure the sum stays within bounds
            }
        }

        // Step 3: Add the value of the current node to the sum
        sum += nodeValues[currentNode];

        // Step 4: Check if the sum is divisible by k
        sum %= k;
        if (sum == 0) componentCount++;

        // Step 5: Return the computed sum for the current subtree
        return sum;
    }
};

approach 2:  BFS

Time complexity: O(n+m)
Space complexity: O(n+m)

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        // Base case: if there are less than 2 nodes, return 1
        if (n < 2) return 1;

        int componentCount = 0;
        unordered_map<int, unordered_set<int>> graph;

        // Step 1: Build the graph
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].insert(node2);
            graph[node2].insert(node1);
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Step 2: Initialize the BFS queue with leaf nodes (nodes with only one
        // connection)
        queue<int> queue;
        for (const auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                queue.push(node);
            }
        }

        // Step 3: Process nodes in BFS order
        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();

            // Find the neighbor node
            int neighborNode = -1;
            if (!graph[currentNode].empty()) {
                neighborNode = *graph[currentNode].begin();
            }

            if (neighborNode >= 0) {
                // Remove the edge between current and neighbor
                graph[neighborNode].erase(currentNode);
                graph[currentNode].erase(neighborNode);
            }

            // Check divisibility of the current node's value
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else if (neighborNode >= 0) {
                // Add current node's value to the neighbor
                longValues[neighborNode] += longValues[currentNode];
            }

            // If the neighbor becomes a leaf node, add it to the queue
            if (neighborNode >= 0 && graph[neighborNode].size() == 1) {
                queue.push(neighborNode);
            }
        }

        return componentCount;
    }
};

approach 3:  TOPOLOGICAL SORT  

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        if (n < 2) return 1;

        int componentCount = 0;
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build the graph and calculate in-degrees
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
            inDegree[node1]++;
            inDegree[node2]++;
        }

        // Convert values to long long to prevent overflow
        vector<long long> longValues(values.begin(), values.end());

        // Initialize the queue with nodes having in-degree of 1 (leaf nodes)
        queue<int> queue;
        for (int node = 0; node < n; node++) {
            if (inDegree[node] == 1) {
                queue.push(node);
            }
        }

        while (!queue.empty()) {
            int currentNode = queue.front();
            queue.pop();
            inDegree[currentNode]--;

            long long addValue = 0;

            // Check if the current node's value is divisible by k
            if (longValues[currentNode] % k == 0) {
                componentCount++;
            } else {
                addValue = longValues[currentNode];
            }

            // Propagate the value to the neighbor nodes
            for (int neighborNode : graph[currentNode]) {
                if (inDegree[neighborNode] == 0) {
                    continue;
                }

                inDegree[neighborNode]--;
                longValues[neighborNode] += addValue;

                // If the neighbor node's in-degree becomes 1, add it to the
                // queue
                if (inDegree[neighborNode] == 1) {
                    queue.push(neighborNode);
                }
            }
        }

        return componentCount;
    }
};