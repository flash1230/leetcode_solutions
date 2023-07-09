/* https://leetcode.com/problems/matrix-block-sum/
1314. Matrix Block Sum
Medium
Array Prefix sum
*/
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> temp(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                temp[i][j] = temp[i - 1][j] + temp[i][j - 1] - temp[i - 1][j - 1];
                temp[i][j] += mat[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans = mat;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int x = max(0, i - k);
                int y = max(0, j - k);
                int c = min(row, i + k + 1);
                int d = min(col, j + k + 1);
                ans[i][j] = temp[c][d] - temp[c][y] - temp[x][d] + temp[x][y];
            }
        }
        return ans;
    }
};