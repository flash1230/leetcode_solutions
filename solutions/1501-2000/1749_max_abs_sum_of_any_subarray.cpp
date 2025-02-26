/* https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
1749. Maximum Absolute Sum of Any Subarray
Medium
DP
*/
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int maxsofar = 0, curmax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                curmax += nums[i];
            else
            {
                maxsofar = max(maxsofar, curmax);
                if (nums[i] + curmax > 0)
                    curmax += nums[i];
                else
                    curmax = 0;
            }
        }
        maxsofar = max(maxsofar, curmax);
        int minsofar = 0;
        curmax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                curmax += nums[i];
            else
            {
                minsofar = min(minsofar, curmax);
                if (nums[i] + curmax < 0)
                    curmax += nums[i];
                else
                    curmax = 0;
            }
        }
        minsofar = min(minsofar, curmax);
        return max(maxsofar, abs(minsofar));
    }
};