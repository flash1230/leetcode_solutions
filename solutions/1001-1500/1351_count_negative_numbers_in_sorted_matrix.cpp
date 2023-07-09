/* https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
1351. Count Negative Numbers in a Sorted Matrix
Easy
Matrix
*/
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            int prev = 0;
            for (int j = prev; j < grid[0].size(); j++)
            {
                if (grid[i][j] < 0)
                {
                    ans += grid[0].size() - j;
                    prev = j;
                    break;
                }
            }
        }
        return ans;
    }
};