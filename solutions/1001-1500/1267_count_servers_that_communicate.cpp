/* https://leetcode.com/problems/count-servers-that-communicate/
1267. Count Servers that Communicate
Medium
*/
class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rows(m, 0);
        vector<int> cols(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    rows[i]++;
                    cols[j]++;
                    ans++;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    if (rows[i] == 1 && cols[j] == 1)
                        ans--;
                }
            }
        }
        return ans;
    }
};