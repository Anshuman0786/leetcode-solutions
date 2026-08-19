class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int r = 0;
        int c = 0;

        if(grid[0][0] != 0)
            return false;
        int dr[] = {1, 1, 2, 2, -1, -1, -2, -2};
        int dc[] = {2, -2, 1, -1, 2, -2, 1, -1};

        for(int step = 1; step < n*n; step++)
        {
            bool found = false;
            for(int k = 0; k < 8; k++)
            {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n)
                {
                    if(grid[nr][nc] == step)
                    {
                        r = nr;
                        c = nc;
                        found = true;
                        break;
                    }
                }
            }
            if(!found)
                return false;
        }

        return true;
    }
};