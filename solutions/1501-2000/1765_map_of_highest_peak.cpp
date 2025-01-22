/* https://leetcode.com/problems/map-of-highest-peak/
1765. Map of Highest Peak
Medium
BFS
*/
class Solution
{
public:
    int m, n;
    bool in_range(int i, int j)
    {
        if (i >= 0 && i < m && j >= 0 && j < n)
            return true;
        return false;
    }
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> bfs;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isWater[i][j])
                {
                    bfs.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while (!bfs.empty())
        {
            int i = bfs.front().first;
            int j = bfs.front().second;
            int val = ans[i][j];
            bfs.pop();
            if (in_range(i + 1, j) && ans[i + 1][j] < 0)
            {
                ans[i + 1][j] = val + 1;
                bfs.push({i + 1, j});
            }
            if (in_range(i - 1, j) && ans[i - 1][j] < 0)
            {
                ans[i - 1][j] = val + 1;
                bfs.push({i - 1, j});
            }
            if (in_range(i, j + 1) && ans[i][j + 1] < 0)
            {
                ans[i][j + 1] = val + 1;
                bfs.push({i, j + 1});
            }
            if (in_range(i, j - 1) && ans[i][j - 1] < 0)
            {
                ans[i][j - 1] = val + 1;
                bfs.push({i, j - 1});
            }
        }
        return ans;
    }
};