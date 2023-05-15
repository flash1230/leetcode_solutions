/* https://leetcode.com/problems/range-sum-query-2d-immutable/
304. Range Sum Query 2D - Immutable
Medium
*/
class NumMatrix
{
public:
    int row, col;
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>> &matrix)
    {
        row = matrix.size();
        col = row > 0 ? matrix[0].size() : 0;
        arr = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                arr[i][j] = matrix[i - 1][j - 1] +
                            arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return arr[row2 + 1][col2 + 1] - arr[row2 + 1][col1] - arr[row1][col2 + 1] + arr[row1][col1];
    }
};