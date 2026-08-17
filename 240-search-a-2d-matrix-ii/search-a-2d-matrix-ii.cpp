class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int coloumn = m-1;

        while(row < n && coloumn >= 0)
        {
            if(matrix[row][coloumn] == target) return true;
            else if(matrix[row][coloumn] > target) coloumn--;
            else row++;
        }
        return false;
    }
};