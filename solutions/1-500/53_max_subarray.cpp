/* https://leetcode.com/problems/maximum-subarray/
53. Maximum Subarray
Medium
*/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int current = nums[0];
        int highest = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int temp = current + nums[i];
            current = max(temp, nums[i]);
            if (current >= highest)
                highest = current;
        }
        return highest;
    }
};