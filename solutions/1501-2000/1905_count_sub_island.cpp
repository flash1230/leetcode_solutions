/* https://leetcode.com/problems/count-sub-islands/
1905. Count Sub Islands
Medium
DFS
*/
class Solution
{
public:
    bool isLand(vector<vector<int>> &grid1, vector<vector<int>> &island)
    {
        for (auto i : island)
        {
            if (!grid1[i[0]][i[1]])
                return false;
        }
        return true;
    }
    bool in_range(int max_row, int max_col, int row, int col)
    {
        if (row >= max_row || row < 0)
            return false;
        if (col >= max_col || col < 0)
            return false;
        return true;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int ans = 0;
        vector<vector<int>> island;
        stack<pair<int, int>> finder;
        int m = grid1.size();
        int n = grid2[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    finder.push({i, j});
                    while (!finder.empty())
                    {
                        int ii = finder.top().first;
                        int jj = finder.top().second;
                        island.push_back({ii, jj});
                        finder.pop();
                        if (in_range(m, n, ii + 1, jj) && grid2[ii + 1][jj])
                        {
                            finder.push({ii + 1, jj});
                            grid2[ii + 1][jj] = 0;
                        }
                        if (in_range(m, n, ii - 1, jj) && grid2[ii - 1][jj])
                        {
                            finder.push({ii - 1, jj});
                            grid2[ii - 1][jj] = 0;
                        }
                        if (in_range(m, n, ii, jj + 1) && grid2[ii][jj + 1])
                        {
                            finder.push({ii, jj + 1});
                            grid2[ii][jj + 1] = 0;
                        }
                        if (in_range(m, n, ii, jj - 1) && grid2[ii][jj - 1])
                        {
                            finder.push({ii, jj - 1});
                            grid2[ii][jj - 1] = 0;
                        }
                    }
                    if (isLand(grid1, island))
                        ans++;
                    island.clear();
                }
            }
        }
        return ans;
    }
};