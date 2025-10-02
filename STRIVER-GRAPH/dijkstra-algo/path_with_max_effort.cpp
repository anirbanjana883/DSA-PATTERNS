1631. Path With Minimum Effort

class Solution {
public:
    // time o(mnn(log(mn)))
    // /space o ( mn)
    typedef pair<int ,pair<int,int>>p;
    vector<vector<int>>direction = {{0,-1},{0,1},{-1,0},{1,0}};
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<p ,vector<p> , greater<p>>pq;
        vector<vector<int>>result(n , vector<int>(m , 1e9));

        result[0][0] = 0;
        // {dist { i , j}}
        pq.push({0, {0 , 0}});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop(); // log(m * n)
            int diff = p.first;
            auto coord = p.second;

            int x = coord.first;
            int y = coord.second;
            auto isSafe = [&](int x ,int y){
                return x >= 0 && y >= 0 && x < n && y < m;
            };
            if(x == n - 1 && y == m - 1) return diff;
            for(auto &dir : direction){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(isSafe(x_ , y_)){
                    int absDiff = abs(grid[x_][y_] - grid[x][y]);
                    int maxDiff = max(diff , absDiff);

                    if( result[x_][y_] > maxDiff){
                        result[x_][y_] = maxDiff;
                        pq.push({maxDiff, { x_ , y_}}); // log(m * n)
                    }
                }
            }
        }
        return result[n - 1][m - 1];
    }
};