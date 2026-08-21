class Solution {
public:


    void solve(int row, int n, vector<vector<string>>& result, vector<string>& board,
               vector<bool>& colUsed, vector<bool>& diag1Used, vector<bool>& diag2Used)
    {
        if(row == n)
        {
            result.push_back(board);
        }
        for(int col=0;col<n;col++)
        {
            
            if(!colUsed[col] && !diag1Used[row-col+n] && !diag2Used[row+col])
            {
                board[row][col] = 'Q';
                colUsed[col] = diag1Used[row-col+n] = diag2Used[row+col] = true;
                solve(row+1, n, result, board, colUsed, diag1Used, diag2Used);
                board[row][col] = '.';
                colUsed[col] = diag1Used[row-col+n] = diag2Used[row+col] = false;
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<bool> colUsed(n, false);
        vector<bool> diag1Used(2*n, false); // index: row-col+n
        vector<bool> diag2Used(2*n, false); // index: row+col
        vector<string> board(n, string(n, '.')); // n x n grid, all '.' initially
        vector<vector<string>> result;
        
        solve(0, n, result, board, colUsed, diag1Used, diag2Used);
        return result;
    }
};