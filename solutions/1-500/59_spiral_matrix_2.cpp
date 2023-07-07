/* https://leetcode.com/problems/spiral-matrix-ii/
59. Spiral Matrix II
Medium
*/
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> vec(n, vector<int>(n));
        int count = 1;
        int startingrow = 0;
        int startingcol = 0;
        int endingrow = n - 1;
        int endingcol = n - 1;
        while (count <= n * n)
        {
            for (int i = startingcol; count <= n * n && i <= endingcol; i++)
                vec[startingrow][i] = count++;
            startingrow++;

            for (int i = startingrow; count <= n * n && i <= endingrow; i++)
                vec[i][endingcol] = count++;
            endingcol--;
            for (int i = endingcol; count <= n * n && i >= startingcol; i--)
                vec[endingrow][i] = count++;
            endingrow--;
            for (int i = endingrow; count <= n * n && i >= startingrow; i--)
                vec[i][startingcol] = count++;
            startingcol++;
        }
        return vec;
    }
};