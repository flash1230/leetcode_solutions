/* https://leetcode.com/problems/house-robber/
198. House Robber
Medium
DP Array
*/
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n];
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[1], nums[0]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0] + nums[2];
        if (n >= 3)
        {
            for (int i = 3; i < nums.size(); i++)
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
        }
        return max(dp[n - 1], dp[n - 2]);
    }
};