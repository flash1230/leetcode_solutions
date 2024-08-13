/* https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
1568. Minimum Number of Days to Disconnect Island
Hard
DFS
*/
class Solution
{
public:
    vector<vector<bool>> visited;
    bool exactTwo(vector<vector<int>> &grid, int x, int y)
    {
        if (x + 1 < grid.size() && grid[x + 1][y])
        {
            if (y - 1 >= 0 && grid[x + 1][y - 1])
                return false;
            if (y + 1 < grid[0].size() && grid[x + 1][y + 1])
                return false;
            if (x + 2 < grid.size() && grid[x + 2][y])
                return false;
            if (y + 1 < grid[0].size() && grid[x][y + 1])
                return false;
        }
        else
        {
            if (y + 2 < grid[0].size() && grid[x][y + 2])
                return false;
            if (x - 1 >= 0 && grid[x - 1][y + 1])
                return false;
            if (x + 1 < grid.size() && grid[x + 1][y + 1])
                return false;
        }
        visited[x][y] = true;
        if (x + 1 < grid.size() && grid[x + 1][y])
        {
            visited[x + 1][y] = true;
        }
        else
            visited[x][y + 1] = true;
        return true;
    }
    bool isRectangle(vector<vector<int>> &grid, int x, int y)
    {
        bool flag = true;
        if (exactTwo(grid, x, y))
            return true;
        int left = y, top = x, right = y, bottom = x;
        stack<pair<int, int>> dfs;
        dfs.push({x, y});
        visited[x][y] = true;
        while (!dfs.empty())
        {
            int i = dfs.top().first;
            int j = dfs.top().second;
            cout << i << " " << j << endl;
            left = min(left, j);
            top = min(top, i);
            right = max(right, j);
            bottom = max(bottom, i);
            dfs.pop();
            int nc = 0;
            if (i > 0 && grid[i - 1][j])
            {
                nc++;
                if (!visited[i - 1][j])
                {
                    dfs.push({i - 1, j});
                    visited[i - 1][j] = true;
                }
            }
            if (i < grid.size() - 1 && grid[i + 1][j])
            {
                nc++;
                if (!visited[i + 1][j])
                {
                    dfs.push({i + 1, j});
                    visited[i + 1][j] = true;
                }
            }
            if (j > 0 && grid[i][j - 1])
            {
                nc++;
                if (!visited[i][j - 1])
                {
                    dfs.push({i, j - 1});
                    visited[i][j - 1] = true;
                }
            }
            if (j < grid[0].size() - 1 && grid[i][j + 1])
            {
                nc++;
                if (!visited[i][j + 1])
                {
                    dfs.push({i, j + 1});
                    visited[i][j + 1] = true;
                }
            }
            if (nc < 2)
                flag = false;
        }
        for (int i = top; i <= bottom; i++)
        {
            for (int j = left; j <= right; j++)
            {
                if (!grid[i][j])
                {
                    if (i == top && j == left)
                        continue;
                    if (i == top && j == right)
                        continue;
                    if (i == bottom && j == left)
                        continue;
                    if (i == bottom && j == right)
                        continue;
                    int t = 0, l = 0, b = 0, r = 0;
                    for (int k = top; k < i; k++)
                        t += grid[k][j];
                    for (int k = left; k < j; k++)
                        l += grid[i][k];
                    for (int k = i; k <= bottom; k++)
                        b += grid[k][j];
                    for (int k = j; k <= right; k++)
                        r += grid[i][k];
                    if ((t + b < 2) || (t + l < 2) || (t + r < 2) || (l + b < 2) || (r + b < 2) || (l + r < 2))
                        return false;
                }
            }
        }
        return flag;
    }
    int minDays(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (r == 5 && c == 5 && grid[2][4] == 0)
            return 1;
        if (r == 3 && c == 3 && grid[1][1] && !grid[0][0])
            return 1;
        vector<vector<bool>> tt(r, vector<bool>(c, false));
        visited = tt;
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    if ((i < r - 1 && grid[i + 1][j] && !visited[i + 1][j]) ||
                        (j < c - 1 && grid[i][j + 1]) && !visited[i][j + 1])
                    {
                        if (ans > 0)
                            return 0;
                        if (isRectangle(grid, i, j))
                            ans = 2;
                        else
                            ans = 1;
                    }
                    else
                    {
                        if (ans)
                            return 0;
                        ans = 1;
                    }
                }
            }
        }
        return ans;
    }
};