/* https://leetcode.com/problems/number-of-islands/
200. Number of Islands
Medium
BFS
*/
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '0' || visited[i][j])
                    continue;
                else
                {
                    ans++;
                    queue<pair<int, int>> bfs;
                    bfs.push({i, j});
                    visited[i][j] = true;
                    while (!bfs.empty())
                    {
                        int ii = bfs.front().first;
                        int jj = bfs.front().second;
                        bfs.pop();
                        if (ii + 1 < n && !visited[ii + 1][jj] && grid[ii + 1][jj] == '1')
                        {
                            visited[ii + 1][jj] = true;
                            bfs.push({ii + 1, jj});
                        }
                        if (ii - 1 > -1 && !visited[ii - 1][jj] && grid[ii - 1][jj] == '1')
                        {
                            visited[ii - 1][jj] = true;
                            bfs.push({ii - 1, jj});
                        }
                        if (jj + 1 < m && !visited[ii][jj + 1] && grid[ii][jj + 1] == '1')
                        {
                            visited[ii][jj + 1] = true;
                            bfs.push({ii, jj + 1});
                        }
                        if (jj - 1 > -1 && !visited[ii][jj - 1] && grid[ii][jj - 1] == '1')
                        {
                            visited[ii][jj - 1] = true;
                            bfs.push({ii, jj - 1});
                        }
                    }
                }
            }
        }
        return ans;
    }
};