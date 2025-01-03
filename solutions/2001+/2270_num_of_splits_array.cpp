/* https://leetcode.com/problems/number-of-ways-to-split-array/
2270. Number of Ways to Split Array
Medium
Prefix Sum
*/
class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long sum = 0;
        for (int num : nums)
            sum += num;
        int ans = 0;
        long long cur = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur += nums[i];
            sum -= nums[i];
            if (cur >= sum)
                ans++;
        }
        return ans;
    }
};