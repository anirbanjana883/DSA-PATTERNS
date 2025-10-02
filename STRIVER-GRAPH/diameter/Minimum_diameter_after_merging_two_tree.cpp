3203. Find Minimum Diameter After Merging Two Trees

its concept is in file see it in the same folder

Time complexity: O(n+m)   for all approach 
space  complexity: O(n+m) for all approach
Approach 1: Farthest of Farthest (BFS)

class Solution {
public:
    pair<int,int>BFS(unordered_map<int,vector<int>>&adj,int source){
        queue<int>q;
        q.push(source);

        unordered_map<int ,bool>visited;

        // mark source as viisted
        visited[source]=true;

        int farthestDisatnce=0;
        int farthestNode=source;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                int currNode=q.front();
                q.pop();

                farthestNode=currNode;
                for(auto &neighbour:adj[currNode]){
                    if(visited[neighbour]==false){
                        visited[neighbour]=true;
                        q.push(neighbour);
                    }
                }
            }
            // when 1 lavel is completed the distance ++;
            if(!q.empty()){
                farthestDisatnce++;
            }
        }
        return {farthestNode,farthestDisatnce};
    }
    int findDiameter(unordered_map<int,vector<int>>&adj){
        // taking a random node 0
        // finding farthest node from this 
        // 1. so if you pick any node(U) and find fartest node from
        //    it(let B) then it(B) must be one end of the diameter
        // 2. now if you find the farthest node from (B) then you will find the
        //  another end of diameter
        // step 1
        auto [farthestNode ,distanceOfFarthestNode]=BFS(adj,0);

        // step 2
        auto [atherEndOfDiameter,diameter]=BFS(adj,farthestNode);
        return diameter;
    }
    unordered_map<int,vector<int>>buildAdj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>>adj;
        for (auto & edge:edges){
            int u=edge[0];
            int v=edge[1]; 

            adj[u].push_back(v);
            adj[v].push_back(u);       
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // stpes
        // make graph
        // connect
        
        // try to choose node that devides the diameter of tree1 and tree2
        // becoz we need to find minimum diameter
        // so dia meter can be (d1+1)/2 + (d2+1)/2 + 1
        // or d1 or d2 

        unordered_map<int,vector<int>>adj1=buildAdj(edges1);
        unordered_map<int,vector<int>>adj2=buildAdj(edges2);

        int d1=findDiameter(adj1);
        int d2=findDiameter(adj2);

        // finding combined diameter
        // becoz we need to find minimum diameter
        int combined = ((d1+1)/2) + ((d2+1)/2) + 1;

        return max({d1 , d2 , combined});
    }
};


Approach 2: Depth First Search [intuion in leetcode this questions note]

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 =
            findDiameter(adjList1, 0, -1).first;  // Start DFS for Tree 1
        int diameter2 =
            findDiameter(adjList2, 0, -1).first;  // Start DFS for Tree 2

        // Calculate the diameter of the combined tree
        // This accounts for the longest path spanning both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum diameter among the two trees and the combined tree
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Helper function to find the diameter of a tree
    // Returns the diameter and the depth of the node's subtree
    pair<int, int> findDiameter(vector<vector<int>>& adjList, int node,
                                int parent) {
        int maxDepth1 = 0,
            maxDepth2 =
                0;  // Tracks the two largest depths from the current node
        int diameter = 0;  // Tracks the diameter of the subtree

        for (int neighbor :
             adjList[node]) {  // Iterate through neighbors of the current node
            if (neighbor == parent)
                continue;  // Skip the parent to avoid cycles

            // Recursively calculate the diameter and depth of the neighbor's
            // subtree
            auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);

            // Update the maximum diameter of the subtree
            diameter = max(diameter, childDiameter);

            depth++;  // Increment the depth to include the edge to this
                      // neighbor
            // Update the two largest depths from the current node
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        // Update the diameter to include the path through the current node
        diameter = max(diameter, maxDepth1 + maxDepth2);

        return {diameter, maxDepth1};
    }
};

Approach 3: Topological Sorting  [intuion in leetcode this questions note]


class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        // Calculate the diameter of both trees
        int diameter1 = findDiameter(n, adjList1);
        int diameter2 = findDiameter(m, adjList2);

        // Output the diameters for debugging (can be removed in production
        // code)
        cout << diameter1 << " " << diameter2 << "\n";

        // Calculate the longest path that spans across both trees.
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Function to find the diameter of a tree using topological sorting
    int findDiameter(int n, vector<vector<int>>& adjList) {
        queue<int> leavesQueue;
        vector<int> degrees(n);
        // Initialize the degree of each node and add leaves (nodes with degree
        // 1) to the queue
        for (int node = 0; node < n; node++) {
            degrees[node] =
                adjList[node].size();  // Degree is the number of neighbors
            if (degrees[node] == 1) {
                leavesQueue.push(node);
            }
        }

        int remainingNodes = n;
        int leavesLayersRemoved = 0;

        // Process the leaves until there are 2 or fewer nodes remaining
        while (remainingNodes > 2) {
            int size = leavesQueue.size();  // Get the number of leaves to
                                            // remove in this iteration
            remainingNodes -= size;
            leavesLayersRemoved++;

            // Remove the leaves from the queue and update the degrees of their
            // neighbors
            for (int i = 0; i < size; i++) {
                int currentNode = leavesQueue.front();
                leavesQueue.pop();

                // Process the neighbors of the current leaf
                for (int neighbor : adjList[currentNode]) {
                    degrees[neighbor]--;  // Decrease the degree of the neighbor
                    if (degrees[neighbor] == 1) {
                        leavesQueue.push(
                            neighbor);  // If the neighbor becomes a leaf, add
                                        // it to the queue
                    }
                }
            }
        }

        // If exactly two nodes remain, return the diameter as twice the number
        // of layers of leaves removed + 1 (as the diameter will include the
        // final connecting edge)
        if (remainingNodes == 2) return 2 * leavesLayersRemoved + 1;

        return 2 * leavesLayersRemoved;
    }
};