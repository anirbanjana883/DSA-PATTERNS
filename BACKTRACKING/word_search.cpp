79. Word Search


Space Complexity: O(L)
Time Complexity: O(M * N * 3^L)
Space Complexity is because of recursion - to store function stack context.
Time Complexity - from every block we go in three adjacent blocks (avoiding the direction we came from). 
This walk can go for max of L times. So each thred at most goes L length long. -> O(3^L).
Now this is applied at each node from main calling function -> O(M * N). Therefore, O(M * N * 3^L).


class Solution {
public:
    vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    bool find(vector<vector<char>>& board, string &word, int i, int j, int idx, int n, int m) {
        if (idx >= word.length()) return true;
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '&') return false;
        if (board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '&';
        for (auto &dir : direction) {
            int i_ = dir[0] + i;
            int j_ = dir[1] + j;
            if (find(board, word, i_, j_, idx+1, n, m)) return true;
        }
        // backtracking 
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        if(m*n < word.size())
            return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(board, word, i, j, 0, n, m)) {
                    return true;
                }
            }
        }
        return false;
    }
};
