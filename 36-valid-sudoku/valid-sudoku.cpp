class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                
                
                if(board[i][j] != '.')
                {
                    for(int k=0;k<9;k++)
                    {
                        // for row and coloumn check
                        if((j != k && board[i][k] == board[i][j]) || (i != k && board[k][j] == board[i][j]))
                        {
                            return false;
                        }
                    }
                    int startRow = 3 * (i / 3);
                    int startCol = 3 * (j / 3);
                    for(int r = startRow; r < startRow + 3; r++)
                    {
                        for(int c = startCol; c < startCol + 3; c++)
                        {
                            if((r != i || c != j) && board[r][c] == board[i][j])
                            {
                                return false;
                            }
                        }
                    }
                }
                
            }
        }
        return true;
    }
};