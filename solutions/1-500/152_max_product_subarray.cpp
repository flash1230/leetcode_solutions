/* https://leetcode.com/problems/maximum-product-subarray/
152. Maximum Product Subarray
Medium
DP
*/
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int highest = nums[0];
        int max_before = nums[0];
        int min_before = nums[0];
        int max_now, min_now;
        for (int i = 1; i < nums.size(); i++)
        {
            max_now = max(nums[i], max(max_before * nums[i], min_before * nums[i]));
            min_now = min(nums[i], min(max_before * nums[i], min_before * nums[i]));
            highest = max(max_now, highest);
            max_before = max_now;
            min_before = min_now;
        }
        return highest;
    }
};
