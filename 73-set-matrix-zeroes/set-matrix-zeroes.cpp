class Solution {
public:
    void sixii(int i,int j,int m, int n, vector<vector<int>>& matrix)
    {
        for(int k=0;k<m;k++)
        {
            matrix[k][j]=0;
        }
        for(int k=0;k<n;k++)
        {
            matrix[i][k]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> zeroo;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    zeroo.push_back({i, j});
                }
            }
        }
        for(int i=0;i<zeroo.size();i++)
        {
            sixii(zeroo[i].first, zeroo[i].second, m, n, matrix);
        }
    }
};