51. N-Queens

class Solution {
public:
    vector<vector<string>>result;
    bool isSafe(int row , int col , vector<string>&board,int n){
        int duplicateRow = row;
        int duplicateCol = col;

        // check for diagonally up-left
        while ( row >= 0 && col >= 0){
            if(board[row][col] == 'Q') return false;
            row-- ; col-- ;
        }
        row = duplicateRow;
        col = duplicateCol;
        // check for row wise left
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = duplicateRow;
        col = duplicateCol;
        // check for diagonally down-left
        while ( row < n && col >= 0){
            if(board[row][col] == 'Q') return false;
            row++ ; col-- ;
        }
        return true;
    }
    void solve (int col , vector<string>&board , int n){
        if ( col == n){
            result.push_back(board);
            return ;
        }

        for ( int row = 0 ; row < n ; row ++){
            if( isSafe( row , col , board , n)){
                board[row][col] = 'Q';
                solve( col + 1 , board ,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // preparing the board
        vector<string> board(n, string(n, '.'));
        // calling the function 
        solve( 0 , board ,n);
        return result;
    }
};
less intutive so can skip for now
class Solution {
public:
    /*
    Time	O(N!)	Due to recursive branching with pruning.
    Space	O(N²)	For storing the board and recursion stack.

    */
    vector<vector<string>>result;
    void solve (int col , vector<string>&board , int n,vector < int > &leftrow,vector < int > &upperDiagonal,vector < int > &lowerDiagonal){
        if ( col == n){
            result.push_back(board);
            return ;
        }

        for ( int row = 0 ; row < n ; row ++){
            if(leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0){
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve( col + 1 , board ,n,leftrow,upperDiagonal,lowerDiagonal);
                board[row][col] = '.';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // preparing the board
        vector<string> board(n, string(n, '.'));
        // calling the function 
        vector < int > leftrow(n, 0);  
        vector < int > upperDiagonal(2 * n - 1, 0);
        vector < int > lowerDiagonal(2 * n - 1, 0);
        solve( 0 , board ,n,leftrow,upperDiagonal,lowerDiagonal);
        return result;
    }
};