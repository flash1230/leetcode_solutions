/* https://leetcode.com/problems/climbing-stairs/
70. Climbing Stairs
Easy
DP
*/
class Solution
{
public:
    int climbStairs(int n)
    {
        int ans[n + 2];
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= n; i++)
            ans[i] = ans[i - 1] + ans[i - 2];
        return ans[n];
    }
};