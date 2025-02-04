/* https://leetcode.com/problems/maximum-ascending-subarray-sum/
1800. Maximum Ascending Subarray Sum
Easy
*/
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int cur = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
                cur += nums[i];
            else
            {
                ans = max(cur, ans);
                cur = nums[i];
            }
        }
        return max(cur, ans);
    }
};