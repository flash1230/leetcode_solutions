/* https://leetcode.com/problems/regions-cut-by-slashes/
959. Regions Cut By Slashes
Medium
BFS
*/
class Solution
{
public:
    int numberOfIslands(vector<vector<bool>> &grid)
    {
        int n = grid.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                    continue;
                else
                {
                    ans++;
                    queue<pair<int, int>> bfs;
                    bfs.push({i, j});
                    grid[i][j] = true;
                    while (!bfs.empty())
                    {
                        int ii = bfs.front().first;
                        int jj = bfs.front().second;
                        bfs.pop();
                        if (ii + 1 < n && !grid[ii + 1][jj])
                        {
                            grid[ii + 1][jj] = true;
                            bfs.push({ii + 1, jj});
                        }
                        if (ii - 1 > -1 && !grid[ii - 1][jj])
                        {
                            grid[ii - 1][jj] = true;
                            bfs.push({ii - 1, jj});
                        }
                        if (jj + 1 < n && !grid[ii][jj + 1])
                        {
                            grid[ii][jj + 1] = true;
                            bfs.push({ii, jj + 1});
                        }
                        if (jj - 1 > -1 && !grid[ii][jj - 1])
                        {
                            grid[ii][jj - 1] = true;
                            bfs.push({ii, jj - 1});
                        }
                    }
                }
            }
        }
        return ans;
    }
    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> isLine(n * 3, vector<bool>(n * 3, 0));
        for (int i = 0, ci = 1; i < n; i++, ci += 3)
        {
            for (int j = 0, cj = 1; j < n; j++, cj += 3)
            {
                if (grid[i][j] == ' ')
                    continue;
                if (grid[i][j] == '\\')
                {
                    isLine[ci][cj] = true;
                    isLine[ci + 1][cj + 1] = true;
                    isLine[ci - 1][cj - 1] = true;
                }
                else
                {
                    isLine[ci][cj] = true;
                    isLine[ci + 1][cj - 1] = true;
                    isLine[ci - 1][cj + 1] = true;
                }
            }
        }
        return numberOfIslands(isLine);
    }
};