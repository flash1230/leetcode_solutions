/* https://leetcode.com/problems/minimum-path-sum/
64. Minimum Path Sum
Medium
*/
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int a = grid.size();
        int b = grid[0].size();
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (i < 1 && j < 1)
                    continue;
                else if (i < 1)
                    grid[0][j] += grid[0][j - 1];
                else if (j < 1)
                    grid[i][0] += grid[i - 1][0];
                else
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[a - 1][b - 1];
    }
};