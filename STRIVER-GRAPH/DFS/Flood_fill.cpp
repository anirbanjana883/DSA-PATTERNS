733. Flood Fill

class Solution {
public:
    // time o( n * m)
    // space o( n * m)
    vector<vector<int>> direction = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    void DFS(vector<vector<int>>& grid, int sr, int sc, int color, int originalColor, vector<vector<bool>>& visited){
        grid[sr][sc] = color;
        visited[sr][sc] = true;

        for(auto &dir : direction){
            int i_ = sr + dir[0];
            int j_ = sc + dir[1];
            if(i_ >= 0 && j_ >= 0 && i_ < grid.size() && j_ < grid[0].size() &&
               !visited[i_][j_] && grid[i_][j_] == originalColor){
                DFS(grid, i_, j_, color, originalColor, visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> result = image;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        DFS(result, sr, sc, color, image[sr][sc], visited);
        return result;
    }
};
