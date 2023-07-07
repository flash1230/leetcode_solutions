/* https://leetcode.com/problems/spiral-matrix
54. Spiral Matrix
Medium
*/
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int startingrow = 0;
        int startingcol = 0;
        int endingrow = row - 1;
        int endingcol = col - 1;
        while (ans.size() < row * col)
        {
            for (int i = startingcol; ans.size() < row * col && i <= endingcol; i++)
                ans.push_back(matrix[startingrow][i]);
            startingrow++;
            for (int i = startingrow; ans.size() < row * col && i <= endingrow; i++)
                ans.push_back(matrix[i][endingcol]);
            endingcol--;
            for (int i = endingcol; ans.size() < row * col && i >= startingcol; i--)
                ans.push_back(matrix[endingrow][i]);
            endingrow--;
            for (int i = endingrow; ans.size() < row * col && i >= startingrow; i--)
                ans.push_back(matrix[i][startingcol]);
            startingcol++;
        }
        return ans;
    }
};