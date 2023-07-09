/* https://leetcode.com/problems/arithmetic-slices/
413. Arithmetic Slices
Medium
DP
*/
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int cur = nums[1] - nums[0];
        int ans = 0;
        int arth_len = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == cur)
            {
                arth_len++;
                ans += arth_len;
            }
            else
            {
                cur = nums[i] - nums[i - 1];
                arth_len = 0;
            }
        }
        return ans;
    }
};