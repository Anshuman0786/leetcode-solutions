class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int,int> prev;
        int step = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(step == 0 && grid[i][j] == step)
                {
                    step++;
                    prev = {i,j};
                }
                else if(grid[i][j] == step)
                {
                    int dr = abs(prev.first - i);
                    int dc = abs(prev.second - j);

                    if((dr==1 && dc==2) || (dr==2 && dc==1))
                    {
                        step++;

                        // Last number has been successfully checked
                        if(step == n*n)
                        {
                            return true;
                        }

                        prev = {i,j};
                        i=-1;
                        break;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return false;
    }
};