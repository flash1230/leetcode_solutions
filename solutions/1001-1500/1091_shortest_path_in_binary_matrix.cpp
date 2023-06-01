/* https://leetcode.com/problems/shortest-path-in-binary-matrix
1091. Shortest Path in Binary Matrix
Medium
BFS
*/
class Solution
{
public:
    int N;
    bool in_range(int i, int j)
    {
        if (i >= 0 && i < N && j >= 0 && j < N)
            return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        N = n;
        if (grid[0][0] || grid[n - 1][n - 1])
        {
            return -1;
        }
        if (n == 1)
        {
            return 1;
        }
        queue<pair<int, int>> bfs;
        bfs.push(make_pair(0, 0));
        int in_this_level = 1;
        int cur_level = 1;
        int next_level = 0;
        while (!bfs.empty())
        {
            int x = bfs.front().first;
            int y = bfs.front().second;
            bfs.pop();
            if (x == n - 1 && y == n - 1)
            {
                return cur_level;
            }
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i == x && j == y)
                        continue;
                    if (in_range(i, j) && !grid[i][j])
                    {
                        grid[i][j] = 1;
                        bfs.push(make_pair(i, j));
                        next_level++;
                    }
                }
            }
            in_this_level--;
            if (!in_this_level)
            {
                cur_level++;
                in_this_level = next_level;
                next_level = 0;
            }
        }
        return -1;
    }
};