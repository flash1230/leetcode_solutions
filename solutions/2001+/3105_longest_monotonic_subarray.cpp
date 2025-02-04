/* https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Easy
*/
class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        char sign;
        int ans = 1, cur = 2;
        if (nums.size() < 2)
            return nums.size();
        if (nums[1] > nums[0])
            sign = 'i';
        else if (nums[1] < nums[0])
            sign = 'd';
        else
        {
            cur = 1;
            ans = 1;
            sign = 's';
        }
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                sign = 's';
                ans = max(ans, cur);
                cur = 1;
            }
            else if (nums[i] > nums[i - 1])
            {
                if (sign == 'i')
                    cur++;
                else
                {
                    ans = max(ans, cur);
                    cur = 2;
                    sign = 'i';
                }
            }
            else
            {
                if (sign == 'd')
                    cur++;
                else
                {
                    ans = max(ans, cur);
                    cur = 2;
                    sign = 'd';
                }
            }
        }
        return max(ans, cur);
    }
};