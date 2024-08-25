/* https://leetcode.com/problems/maximum-number-of-points-with-cost/
1937. Maximum Number of Points with Cost
Medium
DP
*/
class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int col = points[0].size();
        vector<long long> prev(col, 0), cur(col);
        for (int i = 0; i < points.size(); i++)
        {
            long long runner = 0;
            for (int j = 0; j < col; j++)
            {
                runner = max(runner - 1, prev[j]);
                cur[j] = runner;
            }
            runner = 0;
            for (int j = col - 1; j >= 0; j--)
            {
                runner = max(runner - 1, prev[j]);
                cur[j] = max(cur[j], runner) + points[i][j];
            }
            prev = cur;
        }
        long long ans = 0;
        for (int i = 0; i < col; i++)
            ans = max(ans, prev[i]);
        return ans;
    }
};