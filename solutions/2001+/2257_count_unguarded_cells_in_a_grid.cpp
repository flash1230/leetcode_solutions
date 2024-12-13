/* https://leetcode.com/problems/count-unguarded-cells-in-the-grid/
2257. Count Unguarded Cells in the Grid
Medium
*/
class Solution
{
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
    {
        vector<vector<int>> guarded(m, vector<int>(n, 0));
        for (auto wall : walls)
            guarded[wall[0]][wall[1]] = 2;
        for (auto guard : guards)
            guarded[guard[0]][guard[1]] = 3;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto guard : guards)
        {
            for (auto dir : directions)
            {
                int x = guard[0];
                int y = guard[1];
                while (1)
                {
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        break;
                    if (guarded[x][y] == 2 || guarded[x][y] == 3)
                        break;
                    guarded[x][y] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (guarded[i][j] == 0)
                    ans++;
            }
        }
        return ans;
    }
};