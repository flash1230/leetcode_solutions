/* https://leetcode.com/problems/minimum-size-subarray-sum/
209. Minimum Size Subarray Sum
Medium
Sliding Window
*/
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0;
        int end = 0;
        int sum = 0;
        while (end < nums.size())
        {
            sum += nums[end];
            if (sum >= target)
            {
                break;
            }
            end++;
        }
        if (sum < target)
        {
            return 0;
        }
        int ans = end - start + 1;
        if (ans == 1)
        {
            return ans;
        }
        sum -= nums[start];
        start++;
        while (end < nums.size())
        {
            if (sum >= target)
            {
                ans = end - start + 1;
                sum -= nums[start];
                start++;
                if (ans == 1)
                {
                    return ans;
                }
            }
            else
            {
                sum -= nums[start];
                start++;
                if (end == nums.size() - 1)
                    break;
                end++;
                sum += nums[end];
            }
        }
        return ans;
    }
};