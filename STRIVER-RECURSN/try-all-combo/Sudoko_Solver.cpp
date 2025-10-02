37. Sudoku Solver

class Solution {
public:
    // time - 9 ^ 81
    // space - m recursn depth 
    bool isSafe(vector<vector<char>>& board,int row,int col,char c){
        for(int i = 0 ; i < 9 ;i ++){
            // check for same item in same row
            if(board[i][col] == c) return false;
            // check for same item in same col
            if(board[row][i] == c) return false;
            // check for same item in small 3 X 3 square
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        //   check for empty space 
        //  if found empty space then try aut all possible way
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if (board[i][j] == '.'){
                    for (char c = '1'; c <= '9'; c++){ // try all possible
                        if(isSafe(board, i, j, c)){
                            board[i][j] = c;

                            if(solve(board) == true) return true;

                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};