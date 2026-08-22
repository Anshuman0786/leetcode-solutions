class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 subgrid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }


    bool solve(int row, int col, vector<vector<char>>& board)
    {
        if (row == 9) return true;

        if (col == 9) return solve(row + 1, 0, board);

        if (board[row][col] != '.') return solve(row, col + 1, board);
        
        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;

                if (solve(row, col + 1, board)) return true;

                board[row][col] = '.'; 
            }
        }
        return false;
        
    }


    void solveSudoku(vector<vector<char>>& board) {

        solve(0,0,board);
    }
};