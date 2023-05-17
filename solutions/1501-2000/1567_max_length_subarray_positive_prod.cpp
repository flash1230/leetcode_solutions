/* https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
1567. Maximum Length of Subarray With Positive Product
Medium
*/
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return nums[0] > 0 ? 1 : 0;
        }
        int fn = -1, ln = 0, fi = 0, max_len = 0;
        bool positive_prod = true;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (positive_prod)
                {
                    max_len = max(max_len, i - fi);
                }
                else
                {
                    max_len = max(max_len, max(ln - fi, i - fn - 1));
                }
                if (i == n - 1)
                {
                    return max_len;
                }
                fi = i + 1;
                positive_prod = true;
            }
            else
            {
                if (nums[i] < 0)
                {
                    ln = i;
                    positive_prod = !positive_prod;
                    if (fn < fi)
                    {
                        fn = i;
                    }
                }
            }
            if (i == n - 1)
            {
                if (positive_prod)
                {
                    max_len = max(max_len, i - fi + 1);
                }
                else
                {
                    max_len = max(max_len, max(ln - fi, i - fn));
                }
            }
        }
        return max_len;
    }
};