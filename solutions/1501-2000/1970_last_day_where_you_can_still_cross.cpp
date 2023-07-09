/* https://leetcode.com/problems/last-day-where-you-can-still-cross/
1970. Last Day Where You Can Still Cross
Hard
BFS
*/
class Solution
{
public:
    int rows, cols;
    bool in_range(int i, int j)
    {
        if (i > rows - 1 || i < 0)
            return false;
        if (j > cols - 1 || j < 0)
            return false;
        return true;
    }

    bool isPossible(int n, vector<vector<int>> &maty)
    {
        vector<vector<int>> mat = maty;
        queue<pair<int, int>> bfs;
        for (int i = 0; i < cols; i++)
        {
            if (mat[0][i] > n)
                bfs.push({0, i});
        }
        while (!bfs.empty())
        {
            int i = bfs.front().first;
            int j = bfs.front().second;
            bfs.pop();
            mat[i][j] = n - 1;
            for (int a = 0; a < 4; a++)
            {
                int ii, jj;
                if (a == 0)
                {
                    ii = i + 1;
                    jj = j;
                }
                else if (a == 1)
                {
                    ii = i - 1;
                    jj = j;
                }
                else if (a == 2)
                {
                    ii = i;
                    jj = j + 1;
                }
                else
                {
                    ii = i;
                    jj = j - 1;
                }
                if (in_range(ii, jj) && mat[ii][jj] > n)
                {
                    if (ii == rows - 1)
                        return true;
                    else
                    {
                        mat[ii][jj] = n - 1;
                        bfs.push({ii, jj});
                    }
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        rows = row;
        cols = col;
        vector<vector<int>> mat(rows, (vector<int>(cols, 0)));
        for (int i = 0; i < cells.size(); i++)
            mat[cells[i][0] - 1][cells[i][1] - 1] = i + 1;
        int left = col - 1, right = cells.size() - row + 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (isPossible(mid, mat))
                left = mid;
            else
                right = mid;
            if (left == right - 1)
                return left;
        }
        return left;
    }
};