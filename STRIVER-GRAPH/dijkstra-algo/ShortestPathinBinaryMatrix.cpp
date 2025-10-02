1091. Shortest Path in Binary Matrix
important here that dijkstrs algorithm on 2d Matrix
approach 1 since weight not given so this question can be solved by normal bfs only

>sine we will store co-ordinate insted of node in priority queue along with distance so we need 
modification in priority queue to store co-ordinate and distance


class Solution {
public:
    //direction vector 
    vector<vector<int>>direction{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};
    bool is_safe(int x,int y,int n){
        // function to cheak if the cell is inside the matrix or not
        return x>=0 && x<n && y>=0 && y<n;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // if first element is not zero then we can not start
        // we can only visit the node in which 0 present
        int n=grid.size();
        if(n==0||grid[0][0]!=0){
            return -1;
        }
        queue<pair<int,int>>q;
        //co-ordinate of the node
        q.push({0,0});
        // once pushed onto thw queue mark it as 1(visited)
        grid[0][0]=1;
        // count will store the number of transition
        int count=0;
        while(!q.empty()){
            int N=q.size();

            while(N--){
                auto curr=q.front();
                q.pop();

                int x=curr.first;
                int y=curr.second;
                //means we reached the last node
                if(x==n-1 && y==n-1) return count+1;
                // if not the last cell then we will move 
                // smart move to move all the direction
                for(auto &dir:direction){
                    //since we store pair in the direction vector
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                    // now cheaking if the direction is safe or not
                    // if safe then push it onto the queue
                    if(is_safe(x_,y_,n) && grid[x_][y_]==0){
                        q.push({x_,y_});
                        grid[x_][y_]=1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};

code using dijkstra algorithm

class Solution {
public:
    // Define a type alias 'p' to represent the priority queue element:
    // pair<distance, pair<x_coordinate, y_coordinate>>
    typedef pair<int, pair<int, int>> p;

    // All 8 possible directions (horizontal, vertical, and diagonal)
    vector<vector<int>> direction{{1,1},{0,1},{1,0},{-1,0},{0,-1},{-1,-1},{1,-1},{-1,1}};

    // Function to check if the cell (x, y) is inside the grid
    bool is_safe(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Base case: if the start or end cell is blocked
        if (n == 0 || grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }

        // 2D vector to store shortest distance from (0,0) to each cell
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Min-heap priority queue to get the cell with minimum distance so far
        priority_queue<p, vector<p>, greater<p>> pq;

        // Starting cell: push with distance 0
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // Dijkstra's algorithm loop
        while (!pq.empty()) {
            int curr_dist = pq.top().first; // current distance
            pair<int, int> cell = pq.top().second; // current cell coordinates
            int x = cell.first;
            int y = cell.second;
            pq.pop();

            // Explore all 8 directions from the current cell
            for (auto dir : direction) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int wt = 1; // Each move has a weight of 1

                // Check if the new cell is inside the grid, unblocked (0), and if we found a shorter path
                if (is_safe(x_, y_, n) && grid[x_][y_] == 0 && (curr_dist + wt) < dist[x_][y_]) {
                    pq.push({curr_dist + wt, {x_, y_}});
                    dist[x_][y_] = curr_dist + wt; // update distance
                }
            }
        }

        // If the destination cell is unreachable, return -1
        if (dist[n-1][n-1] == INT_MAX) return -1;

        // Return the shortest path length (add +1 to count the starting cell)
        return dist[n-1][n-1] + 1;
    }
};
