/* https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
2684. Maximum Number of Moves in a Grid
Medium
BFS
*/
class Solution
{
public:
    int rows, cols;
    bool in_range(int i, int j)
    {
        if (i > rows - 1 || i < 0)
            return false;
        if (j > cols - 1 || j < 0)
            return false;
        return true;
    }

    int maxMoves(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int j = cols - 2; j >= 0; j--)
        {
            for (int i = 0; i < rows; i++)
            {
                if (in_range(i - 1, j + 1) && grid[i][j] < grid[i - 1][j + 1])
                    dp[i][j] = max(dp[i - 1][j + 1] + 1, dp[i][j]);
                if (in_range(i, j + 1) && grid[i][j] < grid[i][j + 1])
                    dp[i][j] = max(dp[i][j + 1] + 1, dp[i][j]);
                if (in_range(i + 1, j + 1) && grid[i][j] < grid[i + 1][j + 1])
                    dp[i][j] = max(dp[i + 1][j + 1] + 1, dp[i][j]);
            }
        }
        int ans = dp[0][0];
        for (int i = 1; i < rows; i++)
            ans = max(dp[i][0], ans);
        return ans;
    }
};