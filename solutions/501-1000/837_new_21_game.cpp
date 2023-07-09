/* https://leetcode.com/problems/new-21-game/
837. New 21 Game
Medium
DP
*/
class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        if (k + maxPts <= n || k == 0)
            return 1;
        vector<double> dp(n + 1, 0);
        dp[0] = 1;
        double sum = 1.0, ans = 0.0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = sum / maxPts;
            if (i < k)
                sum += dp[i];
            else
                ans += dp[i];
            if (i >= maxPts)
                sum -= dp[i - maxPts];
        }
        return ans;
    }
};