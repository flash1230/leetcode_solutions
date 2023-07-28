/* https://leetcode.com/problems/predict-the-winner
486. Predict the Winner
Medium
Game Theory DP
*/
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
            sum += i;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0; i + gap < n; i++)
            {
                if (gap == 0)
                    dp[i][i] = nums[i];
                else if (gap == 1)
                    dp[i][i + gap] = max(nums[i], nums[i + 1]);
                else
                    dp[i][i + gap] = max(nums[i] + min(dp[i + 2][i + gap], dp[i + 1][i + gap - 1]),
                                         nums[i + gap] + min(dp[i][i + gap - 2], dp[i + 1][i + gap - 1]));
            }
        }
        return (dp[0][n - 1] * 2 >= sum);
    }
};