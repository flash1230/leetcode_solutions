/* https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
712. Minimum ASCII Delete Sum for Two Strings
Medium
DP
*/
class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += s1[i];
        for (int i = 0; i < m; i++)
            ans += s2[i];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (!i || !j)
                    dp[i][j] = 0;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 2 * s1[i - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return ans - dp[n][m];
    }
};