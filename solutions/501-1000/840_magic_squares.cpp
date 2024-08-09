/* https://leetcode.com/problems/magic-squares-in-grid/
840. Magic Squares In Grid
Medium
*/
class Solution
{
public:
    bool diagonal(int a, int b, int c, int d)
    {
        if (a + b == c + d)
            return a + b == 10;
        return false;
    }
    bool areDistinct(vector<vector<int>> &square)
    {
        vector<bool> found(9, false);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (square[i][j] > 9 || square[i][j] == 0)
                    return false;
                if (found[square[i][j]])
                    return false;
                found[square[i][j]] = true;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid[0].size() - 1; j++)
            {
                if (grid[i][j] == 5)
                {
                    if (diagonal(grid[i - 1][j - 1], grid[i + 1][j + 1], grid[i - 1][j + 1], grid[i + 1][j - 1]))
                    {
                        vector<vector<int>> square;
                        for (int t = i - 1; t <= i + 1; t++)
                        {
                            vector<int> temp;
                            for (int u = j - 1; u <= j + 1; u++)
                                temp.push_back(grid[t][u]);
                            square.push_back(temp);
                        }
                        if (areDistinct(square))
                        {
                            if (square[0][0] + square[0][1] + square[0][2] == 15)
                            {
                                if (square[0][0] + square[1][0] + square[2][0] == 15)
                                    ans++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};