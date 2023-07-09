/* https://leetcode.com/problems/stone-game-iv/
1510. Stone Game IV
Hard
DP
*/
class Solution
{
public:
    bool winnerSquareGame(int n)
    {
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= sqrt(i); j++)
            {
                if (!dp[(i - j * j)])
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};