/* https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations
2789. Largest Element in an Array after Merge Operations
Medium
Greedy
*/
class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        int n = nums.size();
        long long cur = nums[n - 1], ans = nums[n - 1];
        for (int i = nums.size() - 2; i > -1; i--)
        {
            if (cur >= nums[i])
                cur += nums[i];
            else
            {
                ans = max(ans, cur);
                cur = nums[i];
            }
        }
        return max(cur, ans);
    }
};